# MiniRT
MinitRT is a project of the 42 School. It is a ray-tracer written C (in collaboration with [Anvently](https://github.com/Anvently)). Given a list of light sources and objects it will render the scene by simulating light transport and some optical effects such as reflection, diffusion...
The user can move in the scene to find the desired point of view. The programm is multi-threaded and you can modify the number of ray emitted per pixel to improve the quality.

The luminosity model is largely based on the [Phong model](https://en.wikipedia.org/wiki/Phong_reflection_model), for each material item different coefficient can be defined to alter its reflective, diffusive, refractive properties...

## Usage

Clone the repository and use the Makefile to build the programm
```
git clone git@github.com:LouisMahe/miniRT.git
```
```
cd miniRT && make
```
The programm takes one argument: a .rt file representing the scene to render. Please refer to the "build_a_scene_helper" to build your own scene.
```
./miniRT scenes/wolf.rt
```

## How to move
The arrows key can be used to move along the axes of your screen. You can scroll to move forward and use the left mouse button to change direction.

## Quality rendering
- Use `[` `]` to decrease\increase the number of threads.
- Use `-` `+` to change the ration of ray per pixel (chunks)

A positive number N of chunks (displayed in the terminal when increased or decreased) means that one ray will be emitted per N pixel. A negative value -N of chunks means that N rays are emitted per pixel and the final luminosity of the pixel is obtained by taking an average
over the rays. Basically the smaller the chunk the better the image.

Lowering the image quality by increasing the number of chunk can make movement smoother since it reduces the amount of computation. Once the desired spot is found you can then decrease the number of chunks again.

## Images from miniRT

![different_properties](/img/properties.png)

_A sphere reflected in a green plane. The scene is ligthened by a source far above. In each picture the plane have different properties_

![checkers](/img/checkers.png)

_An illustration of the two-color checker texture when an even ratio on the left and an odd ration on the right_

![landscape](/img/landscape.png)

_We are inside an immense sphere, the landscape background was mapped onto the interior surface of the sphere. The two balls in the foreground have distinct reflective and refractive coefficient_

![solar_system](/img/sun.gif)

_A demonstration of the rotation and the glowing objects. In this scene the orbiting planet rotates around the star and also around itself. The star has some glowing properties : it behave like a light source for the other objects in the scene
 (it is the only light source in the scene)_

![spooky](/img/spooky_guy.png)

_An assembly of spehres, cones and cylinders to build a spooky guy. The face is obtained with a rather poorly mapped texture of a face, the hat and the skirt use the two-color checker texture_


## Triangle

To display more realistic objects than the one presented above, a solution is to approximate any surface by an assembly of triangles. 
![deer](/img/deers.png)

_A scene taken from [matboivin](https://github.com/matboivin/raytracer), who designed a script to build a .rt scene from a .obj file. This series of images illustrate the render quality with different chunk sizes._

