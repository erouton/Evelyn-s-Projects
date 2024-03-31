'''
Fills image with red
'''
from image import *

def fill(img):
    '''Fills a copy of img with red'''
    copy = img.clone()
    width = copy.get_width()
    height = copy.get_height()
    redpxl = Pixel(255, 0, 0)
    window = ImageWin(width, height)
    for row in range(height):
        for col in range(width):
            copy.set_pixel(col, row, redpxl)
        copy.draw(window)
    return copy

def main():
    raven = FileImage('images//raven_small.jpg')
    width = raven.get_width()
    height = raven.get_height()
    window1 = ImageWin(width, height, "Original Image")
    raven.draw(window1)
    filled_img = fill(raven)
    window2 = ImageWin(width, height, "Filled Image")
    filled_img.draw(window2)

main() #Start Execution
