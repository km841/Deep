import PyPDF2
import pikepdf
import os


def extract_pdf_pages(pdf_file_path, pdf_out_file_path, page_list_to_extract):
    with open(pdf_file_path, 'rb') as src_pdf_file:
        pdf_reader = PyPDF2.PdfFileReader(src_pdf_file)
        pdf_writer = PyPDF2.PdfFileWriter()
        
        for page_number in page_list_to_extract:
            pdf_writer.addPage(pdf_reader.getPage(page_number))

        with open(pdf_out_file_path, 'wb') as out_file:
            pdf_writer.write(out_file)




srcFileName = input("원본 파일 주소를 입력하세요.\n>>")
dstFileName = os.path.dirname(srcFileName) + os.sep + "ResultFiles" + os.sep + os.path.basename(srcFileName)
newdstFileName = os.path.dirname(srcFileName) + os.sep + "ResultFiles" + os.sep + os.path.basename(srcFileName).split('.')[0] + "_new.pdf"

pages = input("추출할 페이지를 입력하세요.(ex. 1 2 3 이런 식으로 페이지는 공백으로 구분)\n>>")
pageList = [int(page) - 1 for page in pages.split()]


if not os.path.exists(os.path.dirname(dstFileName)):
    os.mkdir(os.path.dirname(dstFileName))

input_pdf = pikepdf.Pdf.open(srcFileName)
pdf = pikepdf.Pdf.new()

for n, page in enumerate(input_pdf.pages):
    pdf.pages.append(page)

pdf.save(dstFileName)

extract_pdf_pages(dstFileName,
                  newdstFileName,
                  pageList)

os.remove(dstFileName)
                  
