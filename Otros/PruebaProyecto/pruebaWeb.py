from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.select import Select
import time
import unittest

def prueba():
    chrome_path = r"/Users/kal3b/Documents/Tec/9sem/CyPS/chromedriver"
    driver = webdriver.Chrome(chrome_path)
    driver.get("""https://fs.itesm.mx/adfs/ls/?wa=wsignin1.0&wtrealm=urn%3asharepoint%3amitec&wctx=https%3a%2f%2fmitec.itesm.mx%2f_layouts%2f15%2fAuthenticate.aspx%3fSource%3d%252F""")

    driver.find_element_by_css_selector("#UsernameTextBox").clear()
    driver.find_element_by_css_selector("#UsernameTextBox").send_keys("USUARIO")

    driver.find_element_by_css_selector("#PasswordTextBox").clear()
    driver.find_element_by_css_selector("#PasswordTextBox").send_keys("CONTRASENA")
    driver.find_element_by_css_selector("#ContentPlaceHolder1_SubmitButton").click()
    time.sleep(5)
    
    return driver.current_url

class TestStringMethods(unittest.TestCase):

    def test_upper(self):
        self.assertEqual(prueba(), """https://mitec.itesm.mx/dashboard/index.aspx""")

if __name__ == '__main__':
    unittest.main()

