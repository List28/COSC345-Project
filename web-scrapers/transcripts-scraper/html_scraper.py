'''
Credit : https://github.com/TeHikuMedia/nga-tautohetohe
No license. Most of there other repos say to ask permission, so I've sent them an email, fingers crossed

This file came from a repository with the purpose of searching through all the hansard reports going back to
1854 and finding māori text. I'm only using a file for parsing the hansard reports available on the 
website. And I'm just using a function that will get all the valid links, from 2020 onwards, and feeding 
that to main.py.
'''

# import libraries
from pathlib import Path
from urllib.request import urlopen
from bs4 import BeautifulSoup as bs
from datetime import datetime
import urllib.request

hansard_url = 'https://www.parliament.nz'

# Credit: Chat GPT, because original code resulted in 403 error
user_agent = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'
headers = {'User-Agent': user_agent}

def get_soup_from_url(url):
    request = urllib.request.Request(url, headers=headers)

    response = urllib.request.urlopen(request)
    html_content = response.read()
    return bs(html_content, "html.parser")

def get_new_urls(last_url):
    #rhr_soup = bs(urlopen(f'{hansard_url}{"/en/pb/hansard-debates/rhr/"}'), 'html.parser')

    rhr_soup = get_soup_from_url(f'{hansard_url}{"/en/pb/hansard-debates/rhr/"}')

    new_list = []
    valid_dates = []
    while True:
        #print('\nChecking for new kōrerorero Hansard\n')

        retreivedtime = datetime.now()
        for h2 in rhr_soup.select('ul.hansard__list h2'):
            new_url = h2.a['href']
            if new_url == last_url:
                return new_list
            else:
                #print(new_url)
                new_list.append([retreivedtime, new_url])
                valid_dates.append(new_url[-17:])

        next_page = rhr_soup.find('li', attrs={'class', 'pagination__next'})

        if next_page:
            next_url = f'{hansard_url}{next_page.find("a")["href"]}'
            rhr_soup = get_soup_from_url(next_url)
        else:
            #return new_list
            return valid_dates