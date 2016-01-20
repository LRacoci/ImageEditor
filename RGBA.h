#ifndef _COLOR_H
#define _COLOR_H

class RGBA {
public:
  unsigned char red, green, blue, alpha;
  RGBA();

  RGBA(unsigned char, unsigned char, unsigned char, unsigned char);

  unsigned char brightness() { return (red + green + blue) / 3; }

  RGBA operator*(unsigned char scalar) {
    return RGBA(red * scalar, green * scalar, blue * scalar, alpha);
  }
  RGBA operator/(unsigned char scalar) {
    return RGBA(red / scalar, green / scalar, blue / scalar, alpha);
  }

  RGBA operator+(RGBA color) {
    return RGBA(red + color.red, green + color.green, blue + color.blue, alpha);
  }

  RGBA operator*(RGBA color) {
    return RGBA(red * color.red, green * color.green, blue * color.blue, alpha);
  }
};

RGBA::RGBA() { red = green = blue = 1 << 7; }

RGBA::RGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char s) {
  red = r;
  green = g;
  blue = b;
  alpha = s;
}

#endif
