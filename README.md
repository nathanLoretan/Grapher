# Grapher

## Operations:
*  Base: +, -, \*, /, abs()
*  Power and exponential: ^, e, exp(), ln(), sqrt()
*  Trigonometric: sin(), cos(), tan(), arcsin(), arccos(), arcctan()
*  Separator: {}, [], ()

## Command:
*  setcolor(color): set the color of the selected line
*  setminmax(min, max): rescale axe X and recalculate the coordinates
*  setnbrpoint(nbrPoint): set the resolution

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
f(x1) = 2 * sqrt{[-abs(abs(x) - 1)] * abs[3 - abs(x)] / [(abs(x) - 1) * (3 - abs(x))]} * {1 + abs[abs(x) - 3] / [abs(x) - 3]} * sqrt[1 - (x / 7)^2] + {5 + 0.97 * [abs(x - 0.5) + abs(x + 0.5)] - 3 * [abs(x - 0.75) + abs(x + 0.75)]} * {1 + abs[1 - abs(x)] / [1 - abs(x)]}

f(x2) = (-3) * sqrt[1 - (x / 7)^2] * sqrt{abs[abs(x) - 4]/[abs(x) - 4]}

f(x3) = abs(x / 2) - 0.0913722 * x^2 - 3 + sqrt{1 - [abs(abs(x) - 2) - 1]^2}

f(x4) = {2.71052 + [1.5 - 0.5 * abs(x)] - 1.35526 * sqrt[4 - (abs(x) - 1)^2]} * sqrt{abs[abs(x) - 1] / [abs(x) - 1]}+0.9
```

<img src="https://github.com/nathanLoretan/Grapher/blob/master/Figures/screenshot.PNG">
