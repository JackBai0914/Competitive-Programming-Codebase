# # coding: utf-8
# from PIL import Image, ImageFont

# from handright import Template, handwrite

# text = "我能吞下玻璃而不伤身体。"
# template = Template(
#     background=Image.new(mode="1", size=(1024, 2048), color=1),
#     font_size=100,
#     font=ImageFont.truetype(""),
# )
# images = handwrite(text, template)
# for im in images:
#     assert isinstance(im, Image.Image)
#     im.show()


# coding: utf-8
from PIL import Image, ImageFont

from handright import Template, handwrite

text = """
      我想用AI改变

        金融投资
"""

template = Template(
    background=Image.new(mode="1", size=(3000, 2000), color=1),
    font_size=150,
    font=ImageFont.truetype("Font.ttf"),
    line_spacing=150,
    fill=0,  # 字体“颜色”
    left_margin=100,
    top_margin=100,
    right_margin=100,
    bottom_margin=100,
    word_spacing=0,
    line_spacing_sigma=1,  # 行间距随机扰动
    font_size_sigma=1,  # 字体大小随机扰动
    word_spacing_sigma=1,  # 字间距随机扰动
    end_chars="，。",  # 防止特定字符因排版算法的自动换行而出现在行首
    perturb_x_sigma=1,  # 笔画横向偏移随机扰动
    perturb_y_sigma=1,  # 笔画纵向偏移随机扰动
    perturb_theta_sigma=0.005,  # 笔画旋转偏移随机扰动
)
images = handwrite(text, template)
for i, im in enumerate(images):
    assert isinstance(im, Image.Image)
    im.show()
    im.save("path/to/my/output/{}.webp".format(i))