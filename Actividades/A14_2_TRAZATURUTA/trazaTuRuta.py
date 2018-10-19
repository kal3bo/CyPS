from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.select import Select
import random

chrome_path = r"C:\Users\Kaleb\Desktop\Practica\chromedriver.exe"
driver = webdriver.Chrome(chrome_path)
driver.get("http://app.sct.gob.mx/sibuac_internet/ControllerUI?action=cmdEscogeRuta")

driver.find_element_by_css_selector("#headerEPN > table:nth-child(3) > tbody > tr > td > table > tbody > tr:nth-child(3) > td > table > tbody > tr:nth-child(5) > td > a").click()

obj = Select(driver.find_element_by_name("edoOrigen"))
obj.select_by_index(9)

obj = Select(driver.find_element_by_name("edoDestino"))
obj.select_by_index(23)

obj = Select(driver.find_element_by_name("ciudadOrigen"))
obj.select_by_index(5)

obj = Select(driver.find_element_by_name("ciudadDestino"))
obj.select_by_index(22)

obj = Select(driver.find_element_by_name("edoIntermedio1"))
obj.select_by_index(random.randint(0, 32))

obj = Select(driver.find_element_by_name("ciudadIntermedia1"))
obj.select_by_index(1)

driver.find_element_by_css_selector("#headerEPN > table:nth-child(3) > tbody > tr > td > table > tbody > tr:nth-child(4) > td.abacentro > input").click()
