from selenium import webdriver
chrome_path = r"/Users/kal3b/Documents/Tec/9sem/CyPS/chromedriver"
driver = webdriver.Chrome(chrome_path)
driver.get("http://vancouver.craigslist.com")
driver.find_element_by_xpath("""//*[@id="sss0"]/li[23]/a""").click()
posts = driver.find_elements_by_class_name("hdrlnk")

for post in posts:
    print(post.text)
