
# (c) 2019 FU ZHANG
#Qustion 2

# Imagine you are developing a cross-platform software which helps disabled people who are not able to use the mouse
# comfortably to use a computer. your program should enable the user to the move the mouse cursor using arrow keys on
# the keyboard. press "V" key on the keyboard to simulate the left-click on the mouse. implement the program using Python
# and note that your program should work on all platforms (Windows/Linux/MacOS).
#
# EXAMPLE INPUT
# NONE
#
# EXPECTED OUTPUT:
# NONE




#from pynput.keyboard import Key, Controller
from pynput.keyboard import Key, Listener,KeyCode
from pynput.mouse import Button, Controller

mou = Controller()


def on_press(key):
    pass


def on_release(key):
    print('{0} release'.format(
        key))

    if key == Key.up:
        mou.move(0,-10)

    if key == Key.down:
        mou.move(0,10)

    if key == Key.left:
       mou.move(-10,0)

    if key == Key.right:
       mou.move(10,0)

    if key == KeyCode.from_char('v'):
        print("v")
        mou.click(Button.left, 1)


    if key == Key.esc:
        # Stop listener
        return False

# Collect events until released
with Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()
