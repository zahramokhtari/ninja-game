#include "SBDL.h"

using namespace std;

Texture backv ;
	Texture foreground  ;

	Texture ninja1  ;
	Texture ninja2  ;
	Texture ninja3  ;

	Texture ninja4  ;
	Texture ninja5  ;
	Texture ninja6  ;

	Texture ninjump1  ;
	Texture ninjump2  ;
	Texture ninjump3  ;
	Texture ninjump4  ;

	Texture rope  ;

	Texture s1  ;
	Texture s2 ;
	Texture s3  ;
	Texture s4 ;

	Texture s5 ;
	Texture s6 ;
	Texture s7 ;
	Texture s8 ;


	Texture thrower1 ;
	Texture thrower2 ;

	Texture blade1  ;
	Texture blade2  ;
	Texture blade3 ;
	Texture blade4  ;

	Texture spike1  ;
	Texture spike2 ;


int x ;
int y ;
int z ;
int k ;
int b ;
int a ;
int count  ;
int count2 ;
int state ;
int score ;

SDL_Rect playRect ;
SDL_Rect resumeRect ;
SDL_Rect restartRect ;
SDL_Rect exitRect ;
SDL_Rect menuRect ;
SDL_Rect lose ;
SDL_Rect backgRect ;
SDL_Rect back1Rect ;
SDL_Rect back2Rect ;
SDL_Rect musicRect ;

SDL_Rect thrower ;

SDL_Rect backRect ;
SDL_Rect backRect2 ;

SDL_Rect foregroundRect ;

SDL_Rect ninjaRect ;

SDL_Rect ninjump ;

SDL_Rect ropeRect ;

SDL_Rect squirrels  ;
SDL_Rect squirrels1 ;

SDL_Rect blade ;

SDL_Rect spike1Rect ;
SDL_Rect spike2Rect ;

Texture play ;
Texture exit1 ;
Texture menu ;
Texture restart ;
Texture lose1 ;
Texture resume ;
Texture back ;
Texture back1 ;
Texture back2 ;
Texture score1 ;
Texture music1 ;

Font* font ;
Music* music ;


void showMenu()
{

	if(state == 0)
	{
		back = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/menu/back.jpg") ;
	    backgRect = {0 , 0 , 400 , 600 } ;
        SBDL::showTexture( back , backgRect ) ;

		play = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/menu/PLAYBTN.png") ;
		exit1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/menu/QUITBTN.png") ;

		playRect = {200,300,100,20} ;
        exitRect = {200,320,100,20} ;

		SBDL::showTexture( play , playRect ) ;
		SBDL::showTexture( exit1 , exitRect ) ;

	if(SBDL::mouseInRect(playRect) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_PRESSED))
	{
	state = 1 ;
	score = 0 ;
	}

	else if (SBDL::mouseInRect(exitRect) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_PRESSED))
	{
	state = 2 ;
	}

	else{
	if(state == 0)
		{
	    SBDL::showTexture( play , playRect ) ;
        SBDL::showTexture( exit1, exitRect ) ;
		}
	}
	
	}

	else if(state == 5)
	{
		back1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/menu/PAUSEMENU.png") ;
        SBDL::showTexture( back1 , backgRect ) ;
	
	    resumeRect  = {200,150,100,100} ;
	    resume  = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/menu/PLAYBTN.png") ;

	    music1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/menu/sound_btn.png") ;
	    musicRect = {200,300,100,100} ;

	SBDL::showTexture(music1 , musicRect) ;
	SBDL::showTexture(resume , resumeRect) ;

	if(SBDL::mouseInRect(musicRect) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_PRESSED))
	count2++ ;

	if(count2%2==1)
	SBDL::stopMusic() ;

	if(count2%2==0)
	SBDL::playMusic(music , -1) ;

		if(SBDL::mouseInRect(resumeRect) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_PRESSED))
	    {
		state = 1 ;
	    }	   
   

	    else 
		{
			if(state == 5) 
	    {
		SBDL::showTexture(resume , resumeRect) ;
		SBDL::showTexture(music1 , musicRect) ;	
	    }
		}

	}
		else if(state == 10)
		{
			back2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/menu/gameover_panel.png") ; 
			back2Rect = { 0 , 0,400 ,600} ;
            SBDL::showTexture( back2 , back2Rect ) ;

			SBDL::loadFont("C:/Users/mokht/Desktop/assets/font/Azuki Regular.ttf" , 40) ;
		    lose1 = SBDL::createFontTexture(font,"You Lose ! Your Score = " + to_string(score) , 0 , 0 , 0) ; 
			lose = {100,100,200,30} ;
			SBDL::showTexture(lose1 , lose ) ;

			restart = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/menu/again.png") ;

			restartRect = {200,300,100,100} ;
			SBDL::showTexture(restart , restartRect ) ;

			if(SBDL::mouseInRect(restartRect) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT,1,SDL_PRESSED))
			{
			score = 0 ;
			thrower = {25 , -800 , 60 , 40 } ;
	        backRect  = {0 , 0 , 400 , 600 } ;
	        backRect2 = {0 , -600 , 400 , 600 } ;
	        foregroundRect = {0 , 300 , 400 , 300 } ;
	        ninjaRect = {308 , 500 , 50 , 60 } ;
	        ninjump = {380 , 500 , 50 , 60 } ;
	        ropeRect = {0 , -400 , 400 , 100 } ;
	        squirrels  = {30 , -425 , 60 , 50 } ;
	        squirrels1 = {30 , -425 , 60 , 50 } ;
	        blade = {35 , -425 , 30 , 30 } ;
	        spike1Rect = {35 , -1200 , 40 , 100} ;
	        spike2Rect = {325, -2000 , 40 , 100} ;
			state = 1 ;
			}


			else if(state == 10)
			{
			SBDL::showTexture(restart , restartRect ) ;
			}


		}

}


int main(int argc, char *argv[])
{
	const int window_width = 400;
	const int window_height = 600;
	SBDL::InitEngine("SBDL Test", window_width, window_height);

	const int FPS = 60; //frame per second
	const int delay = 1000 / FPS; //delay we need at each frame

	backv = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/background/back1.png") ;
	foreground = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/background/foreground.png") ;

	ninja1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/1.png") ;
	ninja2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/2.png") ;
	ninja3 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/3.png") ;

	ninja4 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/4.png") ;
	ninja5 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/5.png") ;
	ninja6 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/6.png") ;

	ninjump1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/7.png" ) ;
	ninjump2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/8.png" ) ;
	ninjump3 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/9.png" ) ;
	ninjump4 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/ninjump/run/10.png") ;

	rope = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/obstacles/rope/rope.png") ;

	s1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/obstacles/squirrels/SQ1.png") ;
	s2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/obstacles/squirrels/SQ2.png") ;
	s3 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/obstacles/squirrels/SQ3.png") ;
	s4 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/obstacles/squirrels/SQ4.png") ;

	s5 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/squirrels/SQ5.png") ;
	s6 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/squirrels/SQ6.png") ;
	s7 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/squirrels/SQ7.png") ;
	s8 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/squirrels/SQ8.png") ;


	thrower1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/thrower/thrower.png") ;
	thrower2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/obstacles/thrower/thrower.png") ;

	blade1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/blade/1.png") ;
	blade2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/blade/2.png") ;
	blade3 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/blade/3.png") ;
	blade4 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/blade/4.png") ;

	spike1 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets/obstacles/spike/SPIKES.png") ;
	spike2 = SBDL::loadTexture("C:/Users/mokht/Desktop/assets1/obstacles/spike/SPIKES.png") ;

	font = SBDL::loadFont("C:/Users/mokht/Desktop/assets/font/Azuki Regular.ttf ", 20 ) ;

	music = SBDL::loadMusic("C:/Users/mokht/Desktop/assets1/sound/music.mp3") ;

	thrower = {25 , -800 , 60 , 40 } ;

	backRect  = {0 , 0 , 400 , 600 } ;
	backRect2 = {0 , -600 , 400 , 600 } ;

	foregroundRect = {0 , 300 , 400 , 300 } ;

	ninjaRect = {308 , 500 , 50 , 60 } ;

	ninjump = {380 , 500 , 50 , 60 } ;

	ropeRect = {0 , -400 , 400 , 100 } ;

    squirrels  = {30 , -425 , 60 , 50 } ;
	squirrels1 = {30 , -425 , 60 , 50 } ;

	blade = {35 , -425 , 30 , 30 } ;

	spike1Rect = {35 , -1200 , 40 , 100} ;
	spike2Rect = {325, -2000 , 40 , 100} ;
	
	while (SBDL::isRunning()) {

		int startTime = SBDL::getTime();
		
		SBDL::updateEvents();
		SBDL::clearRenderScreen();

		//Game logic code
		SBDL::playMusic(music , -1) ;

		if(state == 0||state ==5||state==10)
		showMenu() ;

		if (state == 2) 
		break ;

		if(state == 1)
		{
		score1= SBDL::createFontTexture(font , "SCORE = " + to_string(score) ,0,0,0) ;
	    SDL_Rect scoreRect = {0 , 0 ,150 ,50 } ;

		score ++ ;


		SBDL::showTexture(backv , backRect ) ;
		backRect.y+= 1 ;
		SBDL::showTexture(backv , backRect2 ) ;
		backRect2.y+= 1 ;

		if (backRect2.y == 0 )
		{
		backRect.y = -600 ;
		}

		if (backRect.y == 0 )
		{
		backRect2.y = -600 ;
		}

		SBDL::showTexture(thrower1 , thrower ) ;
		thrower.y+= 1 ;

		if(thrower.y>600) 
		thrower.y -= 1200 ;

		SBDL::showTexture(rope , ropeRect ) ;
		    ropeRect.y+= 1 ;

		if(ropeRect.y==600)
		    ropeRect.y = -600 ;

		squirrels.y  = ropeRect.y - 25 ;
		blade.y = thrower.y ;

		if(squirrels.x<0)
		    squirrels.x = 0 ;

		if(count%2 == 0 && ninjump.x >308 ){
		x++ ;

		if(x>0 && x<10 )
		{
			SBDL::showTexture(ninja1 , ninjaRect ) ;
		}

		if(x>10 && x<20 )
		{
			SBDL::showTexture(ninja2 , ninjaRect ) ;
		}

		if(x>20 && x<30 )
		{
			SBDL::showTexture(ninja3 , ninjaRect ) ;
		}

		if(x>30) 
		x = 0 ;
		}
        
		if(count%2 == 1 && ninjump.x <41){
		y++ ;

		if(y>0 && y<15 )
		{
			SBDL::showTexture(ninja4 , ninjaRect ) ;
		}

		if(y>15 && y<30 )
		{
			SBDL::showTexture(ninja5 , ninjaRect ) ;
		}

		if(y>30 && y<45 )
		{
			SBDL::showTexture(ninja6 , ninjaRect ) ;
		}

		if(y>45) 
		y = 0 ;
		}

		if(SBDL::keyPressed(SDL_SCANCODE_SPACE))
		{
		count ++ ;
		}

		if(count%2 == 1 && ninjump.x>40)
		{

			z++ ;

			if (z>0&&z<10)
			{
				SBDL::showTexture(ninjump1 , ninjump ) ;
				ninjump.x-= 10 ;
			}

			if (z>10&&z<20)
			{
				SBDL::showTexture(ninjump2 , ninjump ) ;
				ninjump.x-= 10 ;
			}

			if (z>20&&z<30)
			{
				SBDL::showTexture(ninjump3 , ninjump ) ;
				ninjump.x-= 10 ;
			}

			if (z>30&&z<40)
			{
				SBDL::showTexture(ninjump4 , ninjump ) ;
				ninjump.x-= 10 ;
			}

			if(z>40)
			z = 0 ;

			ninjaRect = {40 , 500 , 50 , 60} ;
			x = -1 ;

		}

		if(count%2 == 0 && ninjump.x<308 )
		{
	    
			z++ ;

			if (z>0&&z<5)
			{
				SBDL::showTexture(ninjump1 , ninjump ) ;
				ninjump.x+=10 ;
			}

			if (z>5&&z<10)
			{
				SBDL::showTexture(ninjump2 , ninjump ) ;
				ninjump.x+=10 ;
			}

			if (z>10&&z<15)
			{
				SBDL::showTexture(ninjump3 , ninjump ) ;
				ninjump.x+=10 ;
			}

			if (z>15&&z<20)
			{
				SBDL::showTexture(ninjump4 , ninjump ) ;
				ninjump.x+=10 ;
			}

			if (z>20)
			    z = 0 ;
				
			ninjaRect = {308 , 500 , 50 , 60 } ;
			y = -1 ;

		}

		if(squirrels.y>100 && squirrels.y<300)
		{
			
			k++ ;

			if(k>0&&k<5)
			{
		        SBDL::showTexture( s1 , squirrels ) ;
			}

			if(k>5&&k<10)
			{
		        SBDL::showTexture( s2 , squirrels ) ;
			}

			if(k>10&&k<15)
			{
		        SBDL::showTexture( s3 , squirrels ) ;
			}

			if(k>15&&k<20)
			{
		        SBDL::showTexture( s4 , squirrels ) ;
				squirrels.x += 8 ;
			}

			if(k>20) 
			k = 0 ;

		}

		if(squirrels.y>300)
		{
			
			b++ ;

			if(b>0&&b<5)
			{
		        SBDL::showTexture( s5 , squirrels ) ;
			}

			if(b>5&&b<10)
			{
		        SBDL::showTexture( s6 , squirrels ) ;
			}

			if(b>10&&b<15)
			{
		        SBDL::showTexture( s7 , squirrels ) ;
			}

			if(b>15&&b<20)
			{
		        SBDL::showTexture( s8 , squirrels ) ;
				squirrels.x -= 8 ;
			}

			if(b>20) 
			b = 0 ; 

		}

		if( blade.y>100 && blade.y <300 )
		{
			
			a++ ;

			if(a>0&&a<5)
			{
		        SBDL::showTexture(  blade1 , blade ) ;
			}

			if(a>5&&a<10)
			{
		        SBDL::showTexture(  blade2 ,  blade ) ;
			}

			if(a>10&&a<15)
			{
		        SBDL::showTexture(  blade3 ,  blade ) ;
			}

			if(a>15&&a<20)
			{
		        SBDL::showTexture(  blade4 ,  blade ) ;
				 blade.x += 10 ;
			}

			if(a>20) 
			a = 0 ;

		}

		if(blade.y >300)
		    blade.x = 0 ;

		if( blade.x>400 )
		    blade.x = 0 ;

		spike1Rect.y++ ;
		spike2Rect.y++ ;

		if(spike1Rect.y == 600)
		spike1Rect.y -= 1800 ;

		if(spike2Rect.y == 600)
		spike2Rect.y -= 2600 ;

		SBDL::showTexture(spike1 , spike1Rect ) ;
		SBDL::showTexture(spike2 , spike2Rect ) ;

		SBDL::showTexture(foreground , foregroundRect ) ;
		foregroundRect.y+= 1 ;

		SBDL::showTexture(score1 , scoreRect ) ;

		if(SBDL::hasIntersectionRect(ninjump ,squirrels ))
		squirrels.y = -700 ;

		if(SBDL::hasIntersectionRect(ninjump ,squirrels1 ))
		squirrels1.y = -700 ;

		if(SBDL::hasIntersectionRect(ninjump ,blade ))
		blade.y = -700 ;
		
		if(SBDL::keyPressed(SDL_SCANCODE_P))
			{
			state = 5 ;
			showMenu() ;
			}

		if(SBDL::hasIntersectionRect(ninjaRect , spike1Rect )|| SBDL::hasIntersectionRect(ninjaRect ,spike2Rect) || SBDL::hasIntersectionRect(ninjaRect ,squirrels) || SBDL::hasIntersectionRect(ninjaRect ,squirrels1) || SBDL::hasIntersectionRect(ninjaRect ,thrower) || SBDL::hasIntersectionRect(ninjaRect ,blade))
		{
			state = 10 ;
		    showMenu() ;
		}

		}
		

		SBDL::updateRenderScreen();
		
		int elapsedTime = SBDL::getTime() - startTime;
		if (elapsedTime < delay)
			SBDL::delay(delay - elapsedTime);

	}
	
}