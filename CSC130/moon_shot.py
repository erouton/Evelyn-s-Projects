'''
Put in a person in exotic locations using greenscreen
'''
import image

def chromakey(fg, bg):
    '''Superimpose the fg on the bg; don't change either one
       The images must be the same size'''
    width = fg.get_width()
    height = fg.get_height()
    new_image = image.EmptyImage(width, height)
    for y in range(height):
        for x in range(width):
            pxl = fg.get_pixel(x, y)
            r = pxl.get_red() #Get red value of the pixel
            g = pxl.get_green()
            b = pxl.get_blue()
            if b > r + g:
                pxl = bg.get_pixel(x, y) #Change to background pixel
            new_image.set_pixel(x, y, pxl) #Copy pxl to the new image
    return new_image

def main():
    '''Controls the program'''
    foreground = image.FileImage("images//blue-mark.jpg")
    background = image.FileImage("images//moon-surface.jpg")
    width = foreground.get_width()
    height = foreground.get_height()
    fg_win = image.ImageWin(width, height, "Foreground")
    bg_win = image.ImageWin(width, height, "Background")
    foreground.draw(fg_win)
    background.draw(bg_win)
    travel_pic = chromakey(foreground, background)
    travel_win = image.ImageWin(width, height, "Travel Image")
    travel_pic.draw(travel_win)

main()
