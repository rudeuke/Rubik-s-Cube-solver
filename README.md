# Rubik-s-Cube-solver
Arduino based robot capable of solving a Rubik's cube by
itself. Thanks to a vision system, it is able to recognize colors, which allows it to examine the current permutation of the puzzle. The optimal sequence of moves required to arrange the cube is then calculated. After it is sent to the microcontroller that controls the servo motors, the previously calculated algorithm is translated into the subsequent movements leading to the solution. The project used technologies such as Arduino and Python, including OpenCV and Kociemba libraries. The individual parts of the robot prototype were created using 3D printing. Designing their 3D models allowed them to be made with the precision required for the device to function properly.

---

### Videos
Prototype: https://www.youtube.com/watch?v=jV8sH8m5a98 <br>
Final (for now) version: https://www.youtube.com/watch?v=nbZvcdUEF0c

---

### Controls
| Key | Description |
| :---: | --- |
| F/B/U/D/L/R | Scan (manually) cube face corresponding to the key pressed |
| 1 | Start automatic scanning |
| 2 | Start scrambling (random) |
| Enter | Start solving (if cube is already scanned) |
| Esc | Exit |

---

### Interface
Current face preview: <br>
![image](https://user-images.githubusercontent.com/76228060/228278837-978810cf-5f13-490b-ad84-4bc8faad1b74.png) <br><br>
Current state of all cube faces: <br>
![image](https://user-images.githubusercontent.com/76228060/228278863-3099ddc4-234c-454d-b52b-faa1652278fc.png)

---

Possible upgrades in the future.
