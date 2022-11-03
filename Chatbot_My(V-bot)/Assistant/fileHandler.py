import subprocess
import wmi
import os
import sys
import webbrowser

if os.path.exists('Files and Document') == False:
	os.mkdir('Files and Document')
path = 'Files and Document/'

def isContain(text, list):
	for word in list:
		if word in text:
			return True
	return False

def createFile(text):
	appLocation = "C:\\Program Files\\Sublime Text 3\\sublime_text.exe"
	
	if isContain(text, ["ppt","power point","powerpoint"]):
		file_name = "sample_file.ppt"
		appLocation = "C:\\Program Files\\Microsoft Office\\root\\Office16\\POWERPNT.EXE"

	elif isContain(text, ['excel','spreadsheet']):
		file_name = "sample_file.xsl"
		appLocation = "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE"

	elif isContain(text, ['word','document']):
		file_name = "sample_file.docx"
		appLocation = "C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE"

	elif isContain(text, ["text","simple","normal"]): file_name = "sample_file.txt"
	else: return "Unable to create this type of file"

	file = open(path + file_name, 'w')
	file.close()
	subprocess.Popen([appLocation, path + file_name])
	return "File is created.\nNow you can edit this file"

