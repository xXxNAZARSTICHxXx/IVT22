program N692e;
const n=9;
type
matrix=array[1..n,1..n] of real;
var
a:matrix;
i,j,t,ii,jj: byte;
max: real;
begin
  randomize;
  //ввод порядка матрицы
  repeat
    writeln('Введите порядок квадратной матрицы не превышающий 9(желательно ввести нечетное число): ');
    readln(t);
  until t<10;
  //заполение матрицы
  for i:=1 to t do
    for j:=1 to t do
      a[i,j]:=99+random(900);
  //поиск максимума В ЗАШТРИХОВАННОМ ДИАПАЗОНЕ    
  max:=a[1,1];
  for i:=1 to t do
    for j:=1 to t do 
      if ((j<=i) and (n-i+1>=j)) or ((j>=i) and (n-i+1<=j)) and (a[i,j]>max) then
         max:=a[i,j]; 
  //вывод массива для проверки и вывод максимального числа      
  for i:=1 to t do begin
    for j:=1 to t do
      write(a[i,j],'  ');
      writeln;
      writeln;
      end;
  writeln('Максимальный элемент = ', max);
end.