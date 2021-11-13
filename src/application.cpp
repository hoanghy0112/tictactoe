/////////////////////////////////////////////////////////
//                                                     //
//                       _oo0oo_                       //
//                      o8888888o                      //
//                      88" . "88                      //
//                      (| -_- |)                      //
//                      0\  =  /0                      //
//                    ___/`---'\___                    //
//                  .' \\|     |// '.                  //
//                 / \\|||  :  |||// \                 //
//                / _||||| -:- |||||- \                //
//               |   | \\\  -  /// |   |               //
//               | \_|  ''\---/''  |_/ |               //
//               \  .-\__  '-'  ___/-. /               //
//             ___'. .'  /--.--\  `. .'___             //
//          ."" '<  `.___\_<|>_/___.' >' "".           //
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |         //
//         \  \ `_.   \_ __\ /__ _/   .-` /  /         //
//     =====`-.____`.___ \_____/___.-`___.-'=====      //
//                       `=---='                       //
//                                                     //
//                                                     //
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     //
//                                                     //
//            KHÔNG BUG!        KHÔNG CRASH!           //
//                                                     //
/////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////
//  Authors:                                           //
//  - Harding Adonis                                   //
//  - Nguyễn Hoàng Hy                                  //
/////////////////////////////////////////////////////////

#include <src/application.hpp>
#include <src/core/board.hpp>

static Application::Ptr s_application;

Application* Application::getInstance()
{
	if (!s_application)
	{
		s_application = std::make_unique<Application>();
	}

	return s_application.get();
}

void Application::run()
{
	Board b(Board::Type::Seven);
	
	// Create window
	InitWindow(900, 500, "Tic Tac Toe");

	// Turn off exit key
	SetExitKey(KEY_NULL);
	
	// Set FPS
	SetTargetFPS(60);
	std::cout << GetFontDefault().recs;
	// Main loop
	while (!WindowShouldClose())
	{
		b.update();

		// Draw anything
		BeginDrawing();
		ClearBackground(BLACK);
		b.draw();
		DrawFPS(0, 0);
		EndDrawing();
	}

	// Destroy window
	CloseWindow();
}