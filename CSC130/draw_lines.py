'''
Draw vertical and horizontal lines across the middle of an image
'''
from image import *

def draw_vline(img):
    '''Draw a vertical red line down the middle of a copy of img'''
    copy = img.clone() #Make a copy of img
    width = copy.get_width()
    height = copy.get_height()
    midx = int(width/2) #Middle position or drawing the line
    for row in range(0, height-1):
        copy.set_pixel(midx, row, Pixel(255, 0, 0))
    return copy

def draw_hline(img):
    '''Draw a horizontal purple line across the middle of a copy of img'''
    copy = img.clone()
    width = copy.get_width()
    height = copy.get_height()
    midy = int(height/2)
    for col in range(0, width):
        copy.set_pixel(col, midy, Pixel(100, 0, 180))
    return copy

def main():
    raven = FileImage('images//raven_small.jpg')
    width = raven.get_width()
    height = raven.get_height()
    window1 = ImageWin(width, height, "Original Image")
    raven.draw(window1)
    raven2 = draw_vline(raven)
    window2 = ImageWin(width, height, "Image with Vertical Line")
    raven2.draw(window2)
    raven3 = draw_hline(raven2)
    window3 = ImageWin(width, height, "Image with Both Line")
    raven3.draw(window3)

main() #Start Execution
