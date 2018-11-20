from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.select import Select
import time
import xlsxwriter

workbook = xlsxwriter.Workbook('Pronosticos.xlsx')
worksheet = workbook.add_worksheet()
worksheet.write(0, 0, "Matricula")
worksheet.write(0, 1, "Nombre")
worksheet.write(0, 2, "Materia")
worksheet.write(0, 3, "Codigo")

chrome_path = r"""C:\Users\Kaleb\Documents\Tec\CyPS\chromedriver"""
driver = webdriver.Chrome(chrome_path)
driver.get("http://10.49.71.125:3000/~certificatec/pronosticos/main/login")

driver.implicitly_wait(3)
driver.find_element_by_css_selector("#login_username").send_keys("ariel.garcia@itesm.mx")
driver.find_element_by_css_selector("#login_password").send_keys("1234")
driver.find_element_by_css_selector("#login_submit").click()
driver.find_element_by_xpath("""//*[@id="nav"]/div/ul/li[7]/a""").click()
driver.find_element_by_css_selector("#sidebar > ul:nth-child(1) > li:nth-child(5)").click()

parentElement = driver.find_element_by_class_name("custom_table")
elementList = parentElement.find_elements_by_tag_name("tr")

row = 1
for i in range(len(elementList)):
    temp = """//*[@id="candidatos_container"]/tbody/tr["""
    temp2 = """]/td[1]/a"""
    temp3 = """]/td[2]/a"""
    selector = str(temp + str(i + 1) + temp2)
    matricula = driver.find_element_by_xpath(selector).text
    nombre = str(temp + str(i + 1) + temp3)
    alumno = driver.find_element_by_xpath(nombre).text
    driver.find_element_by_xpath(selector).click()
    driver.find_element_by_xpath("""/html/body/div[2]/div/div[2]/div[1]/ul[1]/li[3]/a""").click()

    parents = driver.find_element_by_class_name("custom_table")
    childs = parents.find_elements_by_tag_name("tr")
    for j in range(len(childs)):
        tem = "/html/body/div[2]/div/div[2]/div[2]/table/tbody/tr["
        tem2 = "]/td[1]"
        tem3 = "]/td[2]"
        selectorMateria = str(tem + str(j + 1) + tem3)
        materia = driver.find_element_by_xpath(selectorMateria).text
        selectorCodigo = str(tem + str(j + 1) + tem2)
        codigo = driver.find_element_by_xpath(selectorCodigo).text

        worksheet.write(row, 0, matricula)
        worksheet.write(row, 1, alumno)
        worksheet.write(row, 2, materia)
        worksheet.write(row, 3, codigo)
        row += 1

    driver.back()
    driver.back()

workbook.close()
driver.quit()