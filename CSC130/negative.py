'''
Make a negative of an image
while = Pixel(255,255,255)
black = Pixel(0,0,0)
'''
from image import *

def make_negative(img):
    '''Returns a negative of img'''
    copy = img.clone()
    width = copy.get_width()
    height = copy.get_height()
    window = ImageWin(width, height)
    for row in range(height):
        for col in range(width):
            pxl = copy.get_pixel(col, row)
            r = pxl.get_red()
            g = pxl.get_green()
            b = pxl.get_blue()
            new_red = 255 - r
            new_green = 255 - g
            new_blue = 255 - b
            new_pxl = Pixel(new_red, new_green, new_blue)
            copy.set_pixel(col, row, new_pxl)
        copy.draw(window)
    return copy

def main():
    raven = FileImage('images//raven_small.jpg')
    width = raven.get_width()
    height = raven.get_height()
    window1 = ImageWin(width, height, "Original Image")
    raven.draw(window1)
    neg_img = make_negative(raven)
    window2 = ImageWin(width, height, "Negative Image")
    neg_img.draw(window2)

main() #Start Execution
