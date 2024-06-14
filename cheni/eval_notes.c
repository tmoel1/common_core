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

///////////////////////// 