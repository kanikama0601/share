from PIL import Image
path = "/content/udon.png"

def image_gen(num,img_path):
  image = Image.open(img_path)
  if num == 1:
    image = image.convert('L')
  elif num == 2:
    image = image.resize((image.width*2,image.height*3))
  elif num == 3:
    image = image.resize((image.width / 2, image.height / 2))
  elif num == 4:
    image = image.rotate(30,expand=True)
  return image