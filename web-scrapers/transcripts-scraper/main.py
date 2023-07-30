'''
Credit: https://github.com/kayakr/parliament.nz
License: GNU General Public License v2.0

Original converted data to xml formate, I've altered it to put data in csv formate
'''

from bs4 import BeautifulSoup
import urllib.request
import csv
import datetime

from html_scraper import get_new_urls

class Preface:
    title = ""
    link = ""
    date = ""

class Debate:
    title = ""
    subTitle = ""
    speeches = []

class BillDebate:
    title = ""
    subTitle = ""
    speeches = []

class Speech:
    by = ""
    time = ""
    content = []

class SpeechContent:
    type = ""
    name = ""
    text = ""

def flatten(tag):
    content = ""
    for l in tag:
        if l.string == None:
            content = flatten(l)
        else:
            content = content + l.string
    return content


def parseSpeech(tag):
    if tag.find('a'):
        a = tag.a['name']
        p = a.index('_')
        t = a[p + 1:]
    else:
        a = "na"
        p = "na"
        t = "na"

    s = Speech()
    s.content = []
    c = SpeechContent()
    c.type = "Speech"
    f = flatten(tag)
    if not f.find(":") == -1:
        p = f.index(':')
        c.text = f[p + 1:]
        c.name = f[0:p]
    else:
        c.text = f
        c.name = "na"

    s.by = c.name
    s.time = t
    s.content.append(c)
    return s


def parseA(tag):
    sc = SpeechContent()
    sc.text = flatten(tag)
    sc.type = "a"
    return sc


def parseInterjection(tag):
    c = SpeechContent()
    c.type = "Interjection"
    f = flatten(tag)
    p = f.index(':')
    c.text = f[p + 1:]
    c.name = f[0:p]
    return c


def parseContinueSpeech(tag):
    c = SpeechContent()
    c.type = "ContinueSpeech"
    f = flatten(tag)
    if not f.find(":") == -1:
        p = f.index(':')
        c.text = f[p + 1:]
        c.name = f[0:p]
    else:
        c.text = f
        c.name = "na"
    return c


def parseIntervention(tag):
    c = SpeechContent()
    c.type = "Intervention"
    f = flatten(tag)
    p = f.index(':')
    c.text = f[p + 1:]
    c.name = f[0:p]
    return c


# Credit: Chat GPT, because original code resulted in 403 error
user_agent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'
headers = {'User-Agent': user_agent}

def get_soup_from_url(url):
    request = urllib.request.Request(url, headers=headers)
    response = urllib.request.urlopen(request)
    html_content = response.read()
    return BeautifulSoup(html_content, "html.parser")

# dates are stored in tags with this formate: 20230329 14:47:50
def convert_to_datetime(date_string):
    if date_string == "na":
        return "na"
    year = int(date_string[0:4])
    month = int(date_string[4:6])
    day = int(date_string[6:8])
    hour = int(date_string[9:11])
    minute = int(date_string[12:14])
    second = int(date_string[15:17])
    return datetime.datetime(year, month, day, hour, minute, second)

def main(dates):
    bills = []
    debates = []
    preface = Preface()

    for date in dates:
        print(date)
        url = "https://www.parliament.nz/en/pb/hansard-debates/rhr/combined/HansD_" + date

        preface.link = url

        soup = get_soup_from_url(url)
        preface.title = flatten(soup.title)

        count = 1
        for body in soup.find_all('body'):
            n = body.find_all('body')
            for b2 in n:
                p = b2.find_all('p')
                current = None
                currentSpeech = None
                for para in p:
                    #c = para['class'][0]
                    c = para.get('class', [''])[0] #credit: chatgpt
                    if c == "BeginningOfDay":
                        preface.date = flatten(para)
                    elif c == "BillDebate":
                        bill = BillDebate()
                        bill.speeches = []
                        bill.title = flatten(para)
                        bills.append(bill)
                        current = bill
                    elif c == "Debate":
                        debate = Debate()
                        debate.speeches = []
                        debate.title = flatten(para)
                        debates.append(debate)
                        current = debate

                    elif c == "SubDebate":
                        if current != None:
                            current.subTitle = flatten(para)
                    elif c == "Speech":
                        if current != None:
                            if para.find('a'):
                                currentSpeech = parseSpeech(para)
                                current.speeches.append(currentSpeech)
                            else:
                                s = parseContinueSpeech(para)
                                currentSpeech.content.append(s)
                    elif c == "a":
                        if currentSpeech != None:
                            s = parseA(para)
                            if s.name == "":
                                s.name = currentSpeech.by
                            currentSpeech.content.append(s)
                    elif c == "Interjection":
                        if currentSpeech != None:
                            s = parseInterjection(para)
                            currentSpeech.content.append(s)

                    elif c == "ContinueSpeech":
                        if currentSpeech != None:
                            s = parseContinueSpeech(para)
                            currentSpeech.content.append(s)
                    elif c == "Intervention":
                        if currentSpeech != None:
                            s = parseIntervention(para)
                            currentSpeech.content.append(s)

    return debates

def write_debates_to_csv(debates):
    with open("debates.csv", mode='w', newline='', encoding="utf-8" ) as file:
        csv_writer = csv.writer(file)

        csv_writer.writerow(['Title', 'Subtitle', 'DateTime'])
        for debate in debates:
            csv_writer.writerow([debate.title, debate.subTitle, convert_to_datetime(debate.speeches[0].time)])

    with open("speeches.csv", mode='w', newline='', encoding="utf-8") as file:
        csv_writer = csv.writer(file)

        csv_writer.writerow(['By', 'DateTime', 'Debate_Title', 'Debate_Time'])
        for debate in debates:
            for speech in debate.speeches:
                csv_writer.writerow([speech.by, speech.time, debate.title, convert_to_datetime(debate.speeches[0].time)])

    with open("speechContent.csv", mode='w', newline='', encoding="utf-8") as file:
        csv_writer = csv.writer(file)

        csv_writer.writerow(['Type', 'By', 'Text', 'Speech_Time'])
        for debate in debates:
            for speech in debate.speeches:
                for content in speech.content:
                    csv_writer.writerow([content.type, content.name, content.text, convert_to_datetime(speech.time)])


if __name__ == "__main__":

    #valid_dates = get_new_urls("")
    valid_dates = ["20220511_20220511", "20220510_20220510", "20220505_20220505"]

    debates = main(valid_dates)
    write_debates_to_csv(debates)

    #for date in valid_dates:
    #    print(date)
    #    main(date)

    '''
    if len(sys.argv) == 2:
        date = sys.argv[1]
        main(date)
    else:
        print('[*] usage: python scrape.py "DATE"')
        print('[*]   e.g: python scrape.py 20170726')
'''