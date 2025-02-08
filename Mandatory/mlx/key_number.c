#include "../so_long.h"  // For printf()
// #include "mlx.h"    // Include the MiniLibX library

int key_press(int keycode, void *param)
{
    (void)param; // Avoid unused parameter warning
    printf("Key Pressed: %d\n", keycode); // Print the keycode in terminal

    if (keycode == 53) // If ESC key is pressed, exit the program
    {
        printf("Closing window...\n");
        exit(0);
    }
    return (0);
}
// #include "mlx.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();  // Initialize MLX
    win = mlx_new_window(mlx, 800, 600, "Key Test"); // Create a window

    mlx_hook(win, 2, 1L << 0, key_press, NULL); // Register the key press event

    mlx_loop(mlx); // Start the MLX event loop

    return (0);
}