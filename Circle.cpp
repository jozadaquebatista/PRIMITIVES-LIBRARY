namespace PRIMITIVES2D
{

class MouseState
{
private:
public:
	int mx, my;

	MouseState()
	{
		std::clog << "MouseState Constructor Started ... " << std::endl;
		std::clog << "PI: " << M_PI << std::endl;
	}
	void update()
	{
		SDL_GetMouseState(&mx, &my);
	}
}MouseState;

class Circle : public MouseState
{
private:
	float i, j;
public:
	Circle() : MouseState()
	{
		
	}

	~Circle(){ std::clog << "Circle deleted." << std::endl; }

	void update(SDL_Renderer *renderer)
	{

		for(i=100; i>=0; i-=.5)
			for (j=0; j<2*M_PI; j+=0.01)
			{
		   		int x = mx + i*cos(j);
		    	int y = my + i*sin(j);
		    	SDL_SetRenderDrawColor(renderer, 0x00, 0xff, 0x00, 0x00);
				SDL_RenderDrawPoint(renderer, x, y);
		  	}
		for(i=100; i>=99; i-=.5)
			for (j=0; j<2*M_PI; j+=0.01)
			{
		   		int x = mx + i*cos(j);
		    	int y = my + i*sin(j);
		    	SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0x00);
				SDL_RenderDrawPoint(renderer, x, y);
		  	}

		  	SDL_RenderDrawPoint( renderer, 30, 10 );
		  	SDL_RenderDrawPoint( renderer, 10, 30 );
		  	SDL_RenderDrawPoint( renderer, 30, 30 );

		MouseState::update();

	}
}Circle;
} // End of namespace
