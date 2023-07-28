json_file_path = "data.json"

file_path = "output.txt"
with open(file_path, "r") as file:
    text_string = file.read()

new_text = text_string.replace("\\n", "\n")
print(new_text)

with open("newoutput.txt","w") as file:
    file.write(new_text)