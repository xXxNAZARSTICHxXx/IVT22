﻿program N59g; //название программы
var x,y,l,t: real; //действительные числа
begin //начало исполнительной части
  writeln('Введите 2 координаты точки x и y: '); //*дружественный интерфейс*
  readln(x); //вводим x
  readln(y); //вводим y
  t:=-3*x+2; //требуемый пример для условия 
  if (-1<=x) and (x<=1) and (y>=-1) and (y<=t) then // проверяем нахождение координаты в плоскости по всем сторонам
    writeln('Точка находится на плоскости') //*дружественный интерфейс*
    else //иначе
      writeln('Точка не находится на плоскости') //*дружественный интерфейс*
end. //конец программы