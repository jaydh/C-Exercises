/*Jay Howard
Excercise 4.8.3 Complex Numbers
Implement a visualization of the Julia set (of a quadratic polynomial) similar to the Mandelbrot set. The mere difference is that the constant added to the square function is independent of the pixel position. Essentially, you have to introducte a constant k and modify iterate a little.

*Start with k = -0.6 + 0.6i which is a complex Cantor dust, also known as Fatou dust.
*Try other values for k, like 0.353 + 0.288i. Eventually you may want to change the color scheme to come up with a cooler visualization.
*The challenger in software design is to write an implementation for boht Mandelbrot and Julia sets with minimal code redundancy.
*Advances: Both fractals can be combined in an iteractive manner. For this, one has to provide two windows. The first one draws the Mandelbrot set as before In addition, it can enable mouse input so that the complex value under the mouse cursor is used as k for the Julia set in teh second window.
* Pretty advanced: If the calculation of the Julia set is too slwo, one can use thread parallelism or even GPU accerlation with CUDA or OpenGL.
*/


#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <complex>

#ifdef WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

using namespace std;

struct sdl_error {};
inline void sdl_check(bool allclear) { if (!allclear) throw sdl_error(); }

inline void put_pixel(SDL_Surface* screen, int x, int y, uint32_t pixel)
{
	assert(screen->format->BytesPerPixel == 4);
	auto pixel_address = reinterpret_cast<uint32_t*>(screen->pixels) + y * screen->w + x;
	*pixel_address = pixel;
}

class mandel_pixel
{
public:
	mandel_pixel(SDL_Surface* screen, int x, int y, int xdim, int ydim, int max_iter)
		: screen(screen), max_iter(max_iter), iter(0), c(x, y)
	{
		// scale y to [-1.2,1.2] and shift -0.5+0i to the center
		c *= 2.4f / static_cast<float>(ydim);
		c -= complex<float>(1.2 * xdim / ydim + 0.5, 1.2);
		iterate();
	}

	int iterations() const { return iter; }
	uint32_t color() const
	{
		if (iter == max_iter) return SDL_MapRGB(screen->format, 0, 0, 0);
		const int ci = 512 * iter / max_iter; // incremental value for color
											  // return SDL_MapRGB(screen->format, 40*iter & 255, 66*iter & 255, 100*iter & 255);
		return iter < max_iter / 2 ? SDL_MapRGB(screen->format, ci, 0, 0)
			: SDL_MapRGB(screen->format, 255, ci - 255, ci - 255);
	}

private:
	void iterate()
	{
		complex<float> z = c;
		for (; iter < max_iter && norm(z) <= 4.0f; iter++)
			z = z * z + c;
	};

	SDL_Surface* screen;
	const int max_iter;
	int iter;
	complex<float> c;
};

int main(int argc, char* argv[])
{
	const int max_iter = 30;
	int xdim = 1200, ydim = 800;
	if (argc >= 3)
		xdim = atoi(argv[1]), ydim = atoi(argv[2]);

	sdl_check(SDL_Init(SDL_INIT_VIDEO) != -1);
	SDL_Surface* screen = SDL_SetVideoMode(xdim, ydim, 32, SDL_DOUBLEBUF); sdl_check(screen);
	SDL_WM_SetCaption("Mandelbrot's Apple Manikin", "Mandelbrot's Apple Manikin");

	SDL_LockSurface(screen);
	for (int y = 0; y < ydim; y++)
		for (int x = 0; x < xdim; x++) {
			mandel_pixel m(screen, x, y, xdim, ydim, max_iter);
			put_pixel(screen, x, y, m.color());
		}
	SDL_UnlockSurface(screen);
	SDL_Flip(screen);
	// SDL_SaveBMP(screen, "mandelbrot.bmp"); // if you want to save the fractal

	bool run = true;
	while (run) {
		// Polling for events as long as there exists some
		SDL_Event event;
		while (SDL_PollEvent(&event))
			switch (event.type) {
			case SDL_QUIT: run = false; break;
			}
	}
	SDL_Quit();
}
