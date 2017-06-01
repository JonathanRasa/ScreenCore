#include "draw_shapes.h"


void rechthoek(int x_lo, int y_lo, int x_rb, int y_rb, int kleur)
{
	//teken recthoek op bepaalde punten:
	line_fast(x_lo,y_rb, x_rb, y_rb,kleur); //
	line_fast(x_lo,y_lo,x_rb,y_lo,kleur);
	line_fast(x_lo,y_rb, x_lo, y_lo,kleur);
	line_fast(x_rb,y_rb,x_rb,y_lo,kleur);
}

void ellipse_old(int x1, int y1, int height, int width)
{
	int hh = height*height;
	int ww = width*width;
	int hhww = hh*ww;
	int x0 = width;
	int dx = 0;
	int x;
	int y;

	for (x = -width; x <= width; x++)
		UB_VGA_SetPixel(x1 + x, y1,10);

	for (y = 1; y <= height; y++)
	{
		int x1;
		x1 = x0 - (dx - 1);
		for ( ; x1 > 0; x1--)
			if (x1*x1*hh + y*y*ww <= hhww)
				break;
		dx = x0 - x1;
		x0 = x1;

		for (x = -x0; x <= x0; x++)
		{
			UB_VGA_SetPixel(x1 + x, y1 - y,10);
			UB_VGA_SetPixel(x1 + x, y1 + y,10);
		}
	}
}

void ellipse_filled(int x1, int y1, int height, int width)
{
	int y,x;
	double dx,dy;

	for(y = -height; y<=height; y++)
	{
		for(x=-width; x<=width;x++)
		{
			dx = (double)x / (double)width;
			dy = (double)y / (double)height;
			if(dx*dx+dy*dy <= 1)
				UB_VGA_SetPixel(x1+x,y1+y,10);
		}
	}
}

void ellipse(int x1, int y1, int width, int height, int color)
{
	int a2 = width * width;
	int b2 = height * height;
	int fa2 = 4 * a2, fb2 = 4 * b2;
	int x, y, sigma;

	for (x = 0, y = height, sigma = 2*b2+a2*(1-2*height); b2*x <= a2*y; x++)
	{
		UB_VGA_SetPixel(x1+x,y1+y,color);
		UB_VGA_SetPixel(x1-x,y1+y,color);
		UB_VGA_SetPixel(x1+x,y1-y,color);
		UB_VGA_SetPixel(x1-x,y1-y,color);
		if(sigma >= 0)
		{
			sigma += fa2 * (1-y);
			y--;
		}
		sigma += b2 * ((4 * x) + 6);
		}

	for (x = width, y = 0, sigma = 2*a2+b2*(1-2*width); a2*y <= b2*x; y++)
    {
		UB_VGA_SetPixel(x1 + x, y1 + y,color);
		UB_VGA_SetPixel(x1 - x, y1 + y,color);
		UB_VGA_SetPixel(x1 + x, y1 - y,color);
		UB_VGA_SetPixel(x1 - x, y1 - y,color);
        if (sigma >= 0)
        {
            sigma += fb2 * (1 - x);
            x--;
        }
        sigma += a2 * ((4 * y) + 6);
    }
}


void line_fast(int x1, int y1, int x2, int y2, int color)
{
  int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;

  dx=x2-x1;      /* the horizontal distance of the line */
  dy=y2-y1;      /* the vertical distance of the line */
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx=sgn(dx);
  sdy=sgn(dy);
  x=dyabs>>1;
  y=dxabs>>1;
  px=x1;
  py=y1;

  if (dxabs>=dyabs) /* the line is more horizontal than vertical */
  {
    for(i=0;i<dxabs;i++)
    {
      y+=dyabs;
      if (y>=dxabs)
      {
        y-=dxabs;
        py+=sdy;
      }
      px+=sdx;
      UB_VGA_SetPixel(px,py,color);
    }
  }
  else /* the line is more vertical than horizontal */
  {
    for(i=0;i<dyabs;i++)
    {
      x+=dxabs;
      if (x>=dyabs)
      {
        x-=dyabs;
        px+=sdx;
      }
      py+=sdy;
      UB_VGA_SetPixel(px,py,color);
    }
  }
}

void line_fast2(int x1, int y1, int x2, int y2, int thickness, int color)
{
  int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;
  int k;

  dx=x2-x1;      /* the horizontal distance of the line */
  dy=y2-y1;      /* the vertical distance of the line */
  dxabs=abs(dx);
  dyabs=abs(dy);
  sdx=sgn(dx);
  sdy=sgn(dy);
  x=dyabs>>1;
  y=dxabs>>1;
  px=x1;
  py=y1;

  if (dxabs>=dyabs) /* the line is more horizontal than vertical */
  {
    for(i=0;i<dxabs;i++)
    {
      y+=dyabs;
      if (y>=dxabs)
      {
        y-=dxabs;
        py+=sdy;
      }
      px+=sdx;
      for(k=0;k<thickness+1;k++ )
      {
      UB_VGA_SetPixel(px,py+k,color);
      }
    }
  }
  else /* the line is more vertical than horizontal */
  {
    for(i=0;i<dyabs;i++)
    {
      x+=dxabs;
      if (x>=dyabs)
      {
        x-=dyabs;
        px+=sdx;
      }
      py+=sdy;
      for(k=0;k<thickness+1;k++ )
            {
            UB_VGA_SetPixel(px,py+k,color);
            }
    }
  }
}
