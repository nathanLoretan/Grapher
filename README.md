# Grapher

Simple grapher to plot basic functions. The grapher use Qt library and the widget
QCustomPlot.

## Operations:
*  +, -, \*, /, abs()
*  ^, e, exp(), ln(), sqrt()
*  sin(), cos(), tan(), arcsin(), arccos(), arcctan()
*  {}, [], ()

## Command:
*  setcolor(color): Set the color of the selected line
*  setminmax(min, max): Rescale axe-x
*  setnbrpoint(nbrPoint): Set the resolution

## Possible Color:
* green
* blue
* red
* black
* darkblue
* darkred
* darkgreen
* cyan
* magenta
* yellow
* gray

## Try me
```
y1 = 2 * sqrt{[-abs(abs(x) - 1)] * abs[3 - abs(x)] / [(abs(x) - 1) * (3 - abs(x))]} * {1 + abs[abs(x) - 3] / [abs(x) - 3]} * sqrt[1 - (x / 7)^2] + {5 + 0.97 * [abs(x - 0.5) + abs(x + 0.5)] - 3 * [abs(x - 0.75) + abs(x + 0.75)]} * {1 + abs[1 - abs(x)] / [1 - abs(x)]}

y2 = (-3) * sqrt[1 - (x / 7)^2] * sqrt{abs[abs(x) - 4]/[abs(x) - 4]}

y3 = abs(x / 2) - 0.0913722 * x^2 - 3 + sqrt{1 - [abs(abs(x) - 2) - 1]^2}

y4 = {2.71052 + [1.5 - 0.5 * abs(x)] - 1.35526 * sqrt[4 - (abs(x) - 1)^2]} * sqrt{abs[abs(x) - 1] / [abs(x) - 1]}+0.9
```

<img src="https://github.com/nathanLoretan/Grapher/blob/master/Figures/screenshot.PNG">
