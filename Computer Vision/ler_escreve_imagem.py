import keyboard as kb
import numpy as np
import cv2
from mss import mss
from PIL import Image

if __name__ == '__main__':
	sct = mss()
	# Get a screenshot of the 1st monitor
	sct_img = sct.grab(sct.monitors[1])
	# Create an Image
	img = Image.frombytes('RGB', sct_img.size, sct_img.rgb)
	image_to_write = cv2.cvtColor(np.array(img), cv2.COLOR_RGB2BGR)
	cv2.imwrite('imagem.jpeg', image_to_write)
	#cv2.imshow('img', np.array(img))
	#kb.wait("esc")