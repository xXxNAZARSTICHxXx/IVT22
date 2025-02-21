program N692e;
const n=9;
type
matrix=array[1..n,1..n] of real;
var
a:matrix;
t: byte;
max: real;

//ввод порядка матрицы/заполение матрицы
procedure input(var t:byte;var a:matrix);
var
i,j:byte;
begin
  randomize;
  repeat
    writeln('Введите порядок квадратной матрицы не превышающий 9(желательно ввести нечетное число): ');
    readln(t);
  until t<10;

  for i:=1 to t do
    for j:=1 to t do
      a[i,j]:=99+random(900);
end;

//поиск максимума В ЗАШТРИХОВАННОМ ДИАПАЗОНЕ 
procedure maximum(var max:real;var t:byte;var a:matrix);
var
i,j:byte;
begin  
  max:=a[1,1];
  for i:=1 to t do
    for j:=1 to t do 
      if (  ((j<=i)and(t-j+1>=i))or((j>=i)and(t-j+1<=i))  )  and (a[i,j]>max) then
        max:=a[i,j];
end;

//вывод массива для проверки и вывод максимального числа
procedure output(var max:real; var a:matrix; var t:byte);
var
i,j:byte;
begin 
  for i:=1 to t do begin
    for j:=1 to t do
      write(a[i,j],'  ');
      writeln;
      writeln;
      end;
  writeln('Максимальный элемент = ', max);
end;

begin
  input(t,a);
  maximum(max,t,a);
  output(max,a,t);
end.