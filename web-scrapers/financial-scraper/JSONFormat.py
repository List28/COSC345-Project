json_file_path = "data.json"

#^( *\n)* *(J. 7 +)\n( \n)+(\d+ \n)

def stripList(input_list):
    new_list = []
    for line in input_list:
        new_list.append(line.strip())
    return new_list

file_path = "output.txt"
with open(file_path, "r") as file:
    text_string = file.read()

new_text = text_string.replace("\\n", "\n")
new_text_list = new_text.split("\n")

new_text_list = stripList(new_text_list)

print(new_text)

for i, line in enumerate(new_text_list):
    if "J. 7" in line:
        for j in range(3):
            new_text_list.pop(i)

with open("newoutput2.txt","w") as file:
    file.write(new_text)