dofile("game.nut");

local ret = game("SDL GL Test", "With triangles");
ret.fname <- "/sdlgl_test-0.1.1-gk/bin/sdlgl_test";
ret.cwd <- "/sdlgl_test-0.1.1-gk";
ret.screen_w <- 800;
ret.screen_h <- 480;
ret.screen_pf <- GK_PIXELFORMAT_ARGB8888;

ret.keymap <- 
{
	[::GK_KEYSTART] = ::GK_SCANCODE_ESCAPE,
	[::GK_KEYSELECT] = ::GK_SCANCODE_ESCAPE
};

games.append(ret);
