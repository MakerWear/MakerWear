/*

 Basic Lego brick builder module for OpenScad by Jorg Janssen 2013 (CC BY-NC 3.0) 
 To use this in your own projects add:

 use <path_to_this_file/lego_brick_builder.scad>
 brick (length, width, height [,smooth]);

 Length and width are in standard lego brick dimensions. 
 Height is in flat brick heights, so for a normal lego brick height = 3.
 Add optional smooth = true for a brick without studs. 
 Use height = 0 to just put studs/knobs on top of other things.

 */
$fn = 150;
 
 // this is it:
brick(2,2,1);


// and this is how it's done:

FLU = 1.6; // Fundamental Lego Unit = 1.6 mm

BRICK_WIDTH = 5*FLU; // basic brick width
BRICK_HEIGHT = 6*FLU; // basic brick height
PLATE_HEIGHT = 2*FLU; // basic plate height
WALL_THICKNESS = FLU; // outer wall of the brick
STUD_RADIUS = 1.5*FLU; // studs are the small cylinders on top of the brick with the lego logo ('nopje' in Dutch)
STUD_HEIGHT = FLU; 
ANTI_STUD_RADIUS = 0.5*4.07*FLU;  // an anti stud is the hollow cylinder inside bricks that have length > 1 and width > 1
PIN_RADIUS = FLU; // a pin is the small cylinder inside bricks that have length = 1 or width = 1
SUPPORT_THICKNESS = 0.254; // support is the thin surface between anti studs, pins and walls, your printer might not print this thin, try thicker!
EDGE = 0.254; // this is the width and height of the bottom line edge of smooth bricks
CORRECTION = 0.1; // addition to each size, to make sure all parts connect by moving them a little inside each other

module brick(length = 4, width = 2, height = 3, smooth = false){

	// brick shell
	difference(){
		cube(size = [length*BRICK_WIDTH,width*BRICK_WIDTH,height*PLATE_HEIGHT]);
                translate([length*BRICK_WIDTH/2,width*BRICK_WIDTH/2, -1])
        cylinder(h=6, r=0.7);
        translate([length*BRICK_WIDTH/2,width*BRICK_WIDTH/2, -0.1])
        cylinder(h=1, r=2.75);
                translate([length*BRICK_WIDTH/2,width*BRICK_WIDTH/2, 2.3])
        cylinder(h=2, r=1.75);

		translate([WALL_THICKNESS,WALL_THICKNESS,-WALL_THICKNESS])
		union(){
			                    
			// stud inner holes, radius = pin radius


			
		}

	}
	// Studs
	if(!smooth){
		translate([STUD_RADIUS+WALL_THICKNESS,STUD_RADIUS+WALL_THICKNESS,height*PLATE_HEIGHT])
		for (y = [0:width-1]){
			for (x = [0:length-1]){
				translate ([x*BRICK_WIDTH,y*BRICK_WIDTH,-CORRECTION])
				difference(){
					cylinder(h=STUD_HEIGHT+CORRECTION, r=STUD_RADIUS);
					// Stud inner holes
					translate([0,0,-CORRECTION])
					cylinder(h=0.5*STUD_HEIGHT+CORRECTION,r=PIN_RADIUS);

				}
				// tech logo - disable this if your printer isn't capable of printing this small
				if ( length > width){
					translate([x*BRICK_WIDTH+0.8,y*BRICK_WIDTH-1.9,STUD_HEIGHT-CORRECTION])
					resize([1.2*1.7,2.2*1.7,0.254+CORRECTION])
					rotate(a=[0,0,90])
					import("tech.stl");
				}
				else {
					translate([x*BRICK_WIDTH-1.9,y*BRICK_WIDTH-0.8,STUD_HEIGHT-CORRECTION])
					resize([2.2*1.7,1.2*1.7,0.254+CORRECTION])
					import("tech.stl");				
				}				
				/* 
				// Alternative 2-square logo
				translate ([x*BRICK_WIDTH+CORRECTION,y*BRICK_WIDTH-CORRECTION,STUD_HEIGHT-CORRECTION])		
				cube([1,1,2*CORRECTION]);
				translate ([x*BRICK_WIDTH-0.9,y*BRICK_WIDTH-0.9,STUD_HEIGHT-CORRECTION])		
				cube([1,1,0.3]);
				*/				
			}
		}
	}
	
	
}
	