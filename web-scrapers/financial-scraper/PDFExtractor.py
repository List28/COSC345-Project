import sys
import json
import fitz  # PyMuPDF

def extract_text_from_pdf(pdf_file_path):
    text = ""
    with fitz.open(pdf_file_path) as pdf_document:
        for page_num in range(pdf_document.page_count):
            page = pdf_document.load_page(page_num)
            text += page.get_text()

    return text

def convert_to_json(text_data):
    # Customize this function as needed to structure the JSON according to your requirements
    data = {
        "extracted_text": text_data.strip()
    }
    return json.dumps(data, indent=4)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script_name.py <pdf_file>")
        sys.exit(1)

    pdf_file_path = sys.argv[1]

    try:
        extracted_text = extract_text_from_pdf(pdf_file_path)
        json_data = convert_to_json(extracted_text)

        # Replace 'output.json' with the desired JSON output file name
        with open('output.txt', 'w') as output_file:
            output_file.write(json_data)

        print("Text extracted and formatted as JSON successfully!")
    except Exception as e:
        print("Error occurred:", e)
