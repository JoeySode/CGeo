# CGeo

CGeo is a simple C geometry library, giving access to simple 2D geometric structures such as vector2s, circles, and rectangles.
CGeo also provides other functions such as computational and collision functions for each structure.

NOTE: CGeo uses a graph-style coordinate system, meaning lower x values are left, higher are right, and lower y values are lower down, higher y values are further up.

## Instalation

Enter the CGeo directory and run 'make'. This will (hopefully) compile the object files and the final library file 'libcgeo.a' into './build'.
To clean, run 'make clean' which will remove the build folder entirely.

## Usage

```C
float x, y;
scanf("%f", &x);
scanf("%f", &y);

vec2_t v = { x, y };

circ_t c = (circ_t){ -5.0f, 1.0f, 7.0f }; // x, y, radius
rect_t r = (rect_t){ 0.0f, -4.0f, 2.0f, 5.0f }; // x, y, width, height

if (cgCollCircVec(&c, &v) || cgCollRectVec(&r, &v))
    printf("Hit\n");
```

## Contributing

Pull requests are welcome and appreciated.

## License

[MIT](https://choosealicense.com/licenses/mit/)