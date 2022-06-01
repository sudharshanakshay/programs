#!/usr/bin/python3.8

from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
import time


def conf():
	url = 'https://www.indiamart.com/'
	CHROMEDRIVER_PATH = '/home/peter/Desktop/chromedriver_linux64/chromedriver'	
	s = Service(CHROMEDRIVER_PATH)
	driver = webdriver.Chrome(service=s, options=get_options())
	
	try :
		driver.get(url)
	except :
		print('Internet not connected')
		exit()

	#time.sleep(2)
	return driver
	

def get_options():
    browser_locale = 'en'
    chrome_options = Options()
    prefs = {"profile.default_content_setting_values.notifications": 2}
    chrome_options.add_argument("--lang={}".format(browser_locale))
    chrome_options.add_experimental_option("prefs", prefs)
    chrome_options.add_argument('--no-sandbox')
    return chrome_options
    

def startExtract(search_key):

	driver = conf()

	# ------ search for input fleid ------
	SEARCH_ID = 'search-input'
	
	search_bar = driver.find_element(By.ID, SEARCH_ID)
	search_bar.send_keys(search_key)
	
	# ------ hit enter key ------
	
	search_bar.send_keys(Keys.ENTER)
	#time.sleep(3)
	
	# ------ search for Supplier Company name ------
	try : 
		company_list = driver.find_elements(By.XPATH,"/html/body/div[contains(@id, 'app')]/div/main/div[contains(@class,'right-group')]/div[contains(@class, 'flx1')]/section/div[contains(@class, 'prd-bottom')]/h4/a/span")
		
	except : 
		print("couldn't find the element in the path.")
		exit()
	
	# ------ number of Supplier Company found ------
	print('Supplier Company found : '+str(len(company_list)))
	
	# ------ one line gap ------
	print() 
	
	for cmp in company_list :
		print(cmp.text)

	
	driver.close()
	
	

#search_key = 'vermicompost'
search_key = input('search for any product : ')
startExtract(search_key)
	
