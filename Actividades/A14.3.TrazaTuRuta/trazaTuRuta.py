from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.select import Select
import random

chrome_path = r"""C:\Users\Kaleb\Documents\Tec\CyPS\chromedriver"""
driver = webdriver.Chrome(chrome_path)
driver.get("http://app.sct.gob.mx/sibuac_internet/ControllerUI?action=cmdEscogeRuta")

driver.find_element_by_css_selector("#headerEPN > table:nth-child(3) > tbody > tr > td > table > tbody > tr:nth-child(3) > td > table > tbody > tr:nth-child(5) > td > a").click()
driver.find_element_by_css_selector("#headerEPN > table:nth-child(3) > tbody > tr > td > table > tbody > tr:nth-child(3) > td > table > tbody > tr:nth-child(14) > td > a").click()

obj = Select(driver.find_element_by_name("edoOrigen"))
obj.select_by_index(9)

obj = Select(driver.find_element_by_name("edoDestino"))
obj.select_by_index(23)

obj = Select(driver.find_element_by_name("ciudadOrigen"))
obj.select_by_index(5)

obj = Select(driver.find_element_by_name("ciudadDestino"))
obj.select_by_index(22)

obj = Select(driver.find_element_by_name("edoIntermedio1"))
obj.select_by_index(1)

obj = Select(driver.find_element_by_name("ciudadIntermedia1"))
obj.select_by_index(1)

obj = Select(driver.find_element_by_name("tamanioVehiculo"))
obj.select_by_index(2)

obj = Select(driver.find_element_by_name("desplazamiento"))
obj.select_by_index(3)

obj = Select(driver.find_element_by_name("combustible"))
obj.select_by_index(1)

driver.find_element_by_css_selector("#headerEPN > table:nth-child(3) > tbody > tr > td > table > tbody > tr:nth-child(3) > td > table > tbody > tr:nth-child(16) > td:nth-child(2) > input").clear()
driver.find_element_by_css_selector("#headerEPN > table:nth-child(3) > tbody > tr > td > table > tbody > tr:nth-child(3) > td > table > tbody > tr:nth-child(16) > td:nth-child(2) > input").send_keys("8.36")
driver.find_element_by_css_selector("#headerEPN > table:nth-child(3) > tbody > tr > td > table > tbody > tr:nth-child(4) > td.abacentro > input").click()

costoTotalCasetas = driver.find_element_by_css_selector("#tContenido > tbody > tr:nth-child(47) > td:nth-child(5)")
costoTotalCombustible = driver.find_element_by_css_selector("#tContenido > tbody > tr:nth-child(49) > td:nth-child(5)")
costoTotal = driver.find_element_by_css_selector("#tContenido > tbody > tr:nth-child(51) > td:nth-child(5)")
distanciaTotal = driver.find_element_by_css_selector("#tContenido > tbody > tr:nth-child(47) > td:nth-child(2)")
tiempoTotal = driver.find_element_by_css_selector("#tContenido > tbody > tr:nth-child(47) > td:nth-child(3)")


print("El costo total en casetas es de: ${}".format(costoTotalCasetas.text))
print("El costo total en combistible es de: ${}".format(costoTotalCombustible.text))
print("El costo total es de: ${}".format(costoTotal.text))
print("La distancia total es de: {}km".format(distanciaTotal.text))
print("El tiempo total es de: {}hrs".format(tiempoTotal.text))