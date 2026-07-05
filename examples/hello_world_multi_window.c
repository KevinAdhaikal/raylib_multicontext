#include <stdio.h>
#include "raylib.h"

int main() {
	const int WIDTH = 640;
	const int HEIGHT = 360;

	RLContext* window1 = CreateRLContext();
	RLContext* window2 = CreateRLContext();

	SetRLContext(window1);
	InitWindow(WIDTH, HEIGHT, "Window 1");
	SetTargetFPS(60);
	
	SetRLContext(window2);
	InitWindow(WIDTH, HEIGHT, "Window 2");
	SetTargetFPS(60);

	while(!WindowShouldClose()) {
		SetRLContext(window1);

		ClearBackground(BLACK);

		BeginDrawing();
			DrawText("Hello World from Window 1", (WIDTH - MeasureText("Hello World from Window 1", 20)) / 2, HEIGHT / 2, 20, WHITE);
		EndDrawing();

		SetRLContext(window2);
		
		ClearBackground(BLACK);

		BeginDrawing();
			DrawText("Hello World from Window 2", (WIDTH - MeasureText("Hello World from Window 2", 20)) / 2 , HEIGHT / 2, 20, WHITE);
		EndDrawing();
	}

	DeinitRLContext(window1);
	DeinitRLContext(window2);
	return 0;
}
