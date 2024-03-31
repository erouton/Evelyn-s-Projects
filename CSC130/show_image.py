'''
Display an image to the screen
'''
from image import * #Import everything from the image module

raven = FileImage('images//raven_small.jpg')
width = raven.get_width()
height = raven.get_height()
print(width, height)
window = ImageWin(width, height, 'Raven')
raven.draw(window)
redp = Pixel(255, 0, 0) #Create a red pixel
raven.set_pixel(225, 80, redp)
raven.draw(window)
