# miniRT
</br></br>
<div align="center">
  <img src="scenes/spheres.bmp" width="600" height="450"/>
</div>
</br></br></br></br></br>
Part of 42 common core cursus, the aim of this project is to create a little ray tracer in C lang capable of rendering simple geometric figures. For this purpose, a graphics library is needed; here, [MiniLibX](https://github.com/42Paris/minilibx-linux) will be used (MacOS and Linux versions are provided in this repo).  
MiniRT implements the raytracer protocol; reads from a configuration file (must be format .rt) the necessary values to define a series of simple geometric figures in a 3D space, and from there renders an image calculating ray collisions from an (also defined in the configuration file) camera located in this space. Inter-objects collisions and simple lightning management are also implemented.  
  
Usage of the flag [ --save ] saves the rendered image into a .bmp file instead of creating a window.   
Here is the list of implemented geometric objects that can be rendered:  
* Plane
* Sphere
* Cylinder (no caps)
* Square
* Triangle

## Configuration files
Below there is an example of a scene configuration file.
```
R 1920 1080
A 0.2 255,255,255

c 0,30,-100 0,-0.2,1 45

sq -20,10,0   1,0,1 25 72,239,214
sq  10,10,40 -1,0,1 25 12,255,218
sq  0,0,50    0,0,1 80 83,169,175

pl  0,-10,0   0,1,0 133,116,96
pl  0,0,150   0,0,1 20,74,116

sp -20,-7,0 6 203,117,142

l   0,5,-80 0.8 255,255,255
```
### Scene configuration

* **Ambient lightning** (id: A)  
  Defines colour and brightness of default lightning in the scene.  
* **Camera** [id: c]  
  Defines a 'camera' or subjective view of the rendered scene.  
* **Light** [id: l]  
  Defines a light focus, can be coloured.  
### Figure configuration
* **Sphere** [id: sp]  
  Defines an sphere using coordinates of sphere's center, its diameter and colour in RGB.  
* **Plane**  [id: pl]  
  Defines a plane using a point contained in it, its orientation vector and colour.  
* **Square**  [id: sq]  
  Defines a square using its center, side size, orientation vector and colour.  
* **Cylinder**  [id: cy]  
  Defines a cylinder using its center coordinates, orientation vector, diameter, height and colour.  
* **Triangle**  [id: tr]  
  Defines a triangle using three points in the 3D space and colour.

Objects with a cap letter must be defined once, and at least one camera object must be present in the scene configuration.
Please see scenes folder for a complete definition of each element.

## Usage
```
make;
./miniRT path_to_config_file [--save]
```
  
   
_> Project passed with a [100/100] mark <_
