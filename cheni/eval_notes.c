///////////////////// tools 

Let's go through each function one by one and explain how they work, including commentary on the code.

color_pixel
c
Copy code
void	color_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	*buffer;

	buffer = fractal->pointer_to_image;
	buffer[(y * fractal->size_line / 4) + x] = color;
}
This function colors a specific pixel in the image buffer.

Parameters:

t_fractal *fractal: A pointer to the t_fractal struct, which contains information about the fractal being rendered.
int x: The x-coordinate of the pixel to color.
int y: The y-coordinate of the pixel to color.
int color: The color to assign to the pixel, represented as an integer.
Explanation:

int *buffer: A pointer to the start of the image buffer, obtained from fractal->pointer_to_image.
buffer[(y * fractal->size_line / 4) + x] = color: This line calculates the correct index in the buffer for the pixel at (x, y) and assigns it the specified color. fractal->size_line represents the size of a line of pixels in bytes. Dividing by 4 converts bytes to integers since each pixel is represented by an integer (typically 4 bytes).
exit_fractal
c
Copy code
int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}
This function handles the cleanup and exit of the fractal application.

Parameters:

t_fractal *fractal: A pointer to the t_fractal struct, which contains information about the fractal application.
Explanation:

mlx_destroy_image(fractal->mlx, fractal->image): This function call destroys the image created by the MiniLibX library.
mlx_destroy_window(fractal->mlx, fractal->window): This function call destroys the window created by the MiniLibX library.
free(fractal->mlx): This frees the memory allocated for the MiniLibX connection.
free(fractal): This frees the memory allocated for the t_fractal struct.
exit(1): This exits the program with a status code of 1.
return (0): This line is never reached due to the exit(1) call but is included to satisfy the function's return type.
ft_atod
c
Copy code
double	ft_atod(char *s)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0;
	sign = 1;
	power = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\n'))
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s)
		integral = (integral * 10) + (*s++ - '0');
	if (*s == '.')
		++s;
	while (*s)
	{
		power /= 10;
		fractional = fractional + (*s++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}
This function converts a string to a double, similar to atof in the C standard library.

Parameters:

char *s: A pointer to the string to be converted.
Explanation:

long integral: Variable to store the integral part of the number.
double fractional: Variable to store the fractional part of the number.
double power: Variable to manage the decimal place value for the fractional part.
int sign: Variable to manage the sign of the number (positive or negative).
Steps:

Initialize integral, fractional, sign, and power.
Skip whitespace characters.
Check for a sign and adjust sign accordingly.
Parse the integral part of the number until a dot or end of string is encountered.
If a dot is encountered, start parsing the fractional part:
For each digit, adjust the power to represent the decimal place and accumulate the fractional value.
Combine integral and fractional, apply the sign, and return the result.
Commentary
color_pixel:

This function directly manipulates the image buffer to color a specific pixel. It's essential to understand the image buffer layout to correctly calculate the index.
exit_fractal:

This function ensures proper cleanup of resources before exiting the application. It's crucial in a graphical application to free resources to avoid memory leaks.
ft_atod:

This function is a custom implementation of string-to-double conversion. It handles leading whitespace, optional sign, integral part, and fractional part of the number. Understanding the conversion process helps in debugging issues related to numerical input parsing.







Certainly! Let's break down the line buffer[(y * fractal->size_line / 4) + x] = color; in greater detail, considering the context of graphical programming and how image buffers are typically structured.

Understanding the Components
buffer:

buffer is a pointer to the image buffer, which is a contiguous block of memory that stores pixel data for an image.
y * fractal->size_line:

y represents the row index (or y-coordinate) of the pixel within the image.
fractal->size_line is the number of bytes per row of the image (often called the "stride" or "pitch" of the image). This value can include padding bytes added to align each row to a specific boundary.
Multiplying y by fractal->size_line gives the starting byte offset for the row y in the buffer.
/ 4:

Since each pixel is typically represented by an integer (4 bytes in most cases, for example, in formats like ARGB or RGBA), we divide the byte offset by 4 to convert it from a byte offset to a pixel offset.
This division ensures that we are indexing the buffer correctly in terms of pixels rather than bytes.
+ x:

x represents the column index (or x-coordinate) of the pixel within the row.
Adding x to the row's starting pixel offset gives the exact position of the pixel (x, y) in the buffer.
= color:

color is the integer value representing the color to be assigned to the pixel. This integer can encode the color in a specific format (e.g., 0xAARRGGBB for ARGB, where AA is the alpha channel, and RR, GG, BB are the red, green, and blue channels, respectively).
Complete Breakdown
Calculating the Row Offset:

The expression y * fractal->size_line computes the total number of bytes from the beginning of the buffer to the start of row y.
This is necessary because each row might have padding bytes added to maintain alignment, making the row length in bytes (fractal->size_line) potentially longer than the width of the image in pixels.
Converting Bytes to Pixels:

By dividing the byte offset by 4 (/ 4), we convert the offset from bytes to pixels. This works under the assumption that each pixel is represented by 4 bytes (an integer).
Calculating the Pixel Index:

Adding x to the pixel offset of the row gives the exact pixel index within the buffer.
Setting the Pixel Color:

buffer[(y * fractal->size_line / 4) + x] = color; sets the pixel at position (x, y) in the buffer to the specified color.
Visualization
Let's visualize an example with a small 4x4 image (assuming each pixel is represented by 4 bytes and there is no padding, so size_line would be 4 * 4 = 16 bytes):

bash
Copy code
Buffer (in memory, assuming 1 pixel = 1 integer):
[ P00, P01, P02, P03, P10, P11, P12, P13, P20, P21, P22, P23, P30, P31, P32, P33 ]
To set the color of pixel (2, 1):
x = 2, y = 1
fractal->size_line = 16
Calculate the byte offset for row y: 1 * 16 = 16
Convert to pixel offset: 16 / 4 = 4 (since each pixel is 4 bytes)
Add x: 4 + 2 = 6
Set the color: buffer[6] = color
Summary
This line of code is a direct manipulation of the image buffer to set the color of a specific pixel. It leverages the stride (or pitch) of the image to correctly calculate the pixel's index, ensuring that the pixels are accessed and modified correctly even if there is padding in each row. This is crucial in graphical programming where efficiency and accuracy are paramount.


///////////////////////// main

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	// Check if the program has received at least one argument.
	if (argc < 2)
	{
		// If not, print a usage message and exit.
		ft_printf("Try: ./fractol <fractal>\nFractols: mandelbrot or julia");
		return (0);
	}

	// Allocate memory for the fractal structure.
	fractal = malloc(sizeof(t_fractal));
	
	// Initialize the fractal structure with default values.
	init_fractal(fractal);
	
	// Initialize the MiniLibX library and create a new window.
	init_mlx(fractal);
	
	// Set up a hook to handle keyboard events.
	// `key_hook` is the function that will be called when a key is pressed.
	mlx_key_hook(fractal->window, key_hook, fractal);
	
	// Set up a hook to handle mouse events.
	// `mouse_hook` is the function that will be called when a mouse event occurs.
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	
	// Set up a hook to handle window close events.
	// When the window's close button is clicked, `exit_fractal` will be called.
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	
	// Draw the initial fractal based on the command line arguments.
	// `draw_first_fractal` determines which fractal to draw and handles it accordingly.
	draw_first_fractal(fractal, argc, argv);
	
	// Enter the MiniLibX main loop.
	// This loop waits for events (like key presses or mouse clicks) and handles them.
	mlx_loop(fractal->mlx);
	
	// Return 0 to indicate successful execution.
	return (0);
}


///////////////////////// init


#include "../fractol.h"

// Initialize the fractal structure with default values.
void	init_fractal(t_fractal *fractal)
{
	// Set initial x coordinate to 0.
	fractal->x = 0;

	// Set initial y coordinate to 0.
	fractal->y = 0;

	// Set the initial color to a predefined color code.
	fractal->color = COLOR_CODE;

	// Set the initial zoom level to 300. 
	// This controls how zoomed in the fractal is.
	fractal->zoom = 300;

	// Set the initial horizontal offset. 
	// This shifts the fractal left or right in the window.
	fractal->offset_x = -2.25;

	// Set the initial vertical offset. 
	// This shifts the fractal up or down in the window.
	fractal->offset_y = -1.65;

	// Set the maximum number of iterations for the fractal computation. 
	// This determines how detailed the fractal is.
	fractal->max_iterations = MAX_ITERATIONS;
}

// Initialize the MiniLibX (mlx) library and create the window and image.
void	init_mlx(t_fractal *fractal)
{
	// Initialize the MiniLibX library. 
	// This sets up the connection to the display.
	fractal->mlx = mlx_init();

	// Create a new window with a title "Fract-ol".
	// SIZE is used for both width and height of the window.
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");

	// Create a new image with the same dimensions as the window.
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);

	// Get a pointer to the image data and store it in the structure.
	// This allows direct manipulation of the image pixels.
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, // Number of bits per pixel
			&fractal->size_line, // Size of one line of the image in bytes
			&fractal->endian); // Endianess of the pixel data
}



////////////////////////// events



#include "../fractol.h"

// Function to handle zooming in and out of the fractal
void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;

	// Define the zoom level increment
	zoom_level = 1.42;

	// Check if zooming in
	if (zoom == 1)
	{
		// Calculate new horizontal offset
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) 
		                    - (x / (fractal->zoom * zoom_level));
		
		// Calculate new vertical offset
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) 
		                    - (y / (fractal->zoom * zoom_level));
		
		// Increase the zoom level
		fractal->zoom *= zoom_level;
	}
	// Check if zooming out
	else if (zoom == -1)
	{
		// Calculate new horizontal offset
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) 
		                    - (x / (fractal->zoom / zoom_level));
		
		// Calculate new vertical offset
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) 
		                    - (y / (fractal->zoom / zoom_level));
		
		// Decrease the zoom level
		fractal->zoom /= zoom_level;
	}
	else
		return ; // If zoom is not 1 or -1, do nothing
}

// Function to handle key press events
int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1); // Exit the program if ESC key is pressed
	else if (key_code == LEFT)
		fractal->offset_x -= 42 / fractal->zoom; // Move left
	else if (key_code == RIGHT)
		fractal->offset_x += 42 / fractal->zoom; // Move right
	else if (key_code == UP)
		fractal->offset_y -= 42 / fractal->zoom; // Move up
	else if (key_code == DOWN)
		fractal->offset_y += 42 / fractal->zoom; // Move down
	
	// Redraw the fractal with updated parameters
	draw_fractal(fractal, fractal->name);
	return (0);
}

// Function to handle mouse events
int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1); // Zoom in
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1); // Zoom out
	
	// Redraw the fractal with updated parameters
	draw_fractal(fractal, fractal->name);
	return (0);
}






///////////////////////////// draw