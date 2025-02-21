program N694a;
const t = 9;
type
matrix=array[1..t,1..t] of integer;
var
a:matrix;
n:byte;

//ввод ограничителя порядка
procedure limit(var n:byte);
var
i,j:byte;
begin
  repeat
    writeln('Введи порядок матрицы, меньше 10, но больше 5: ');
    readln(n);
  until (n<10) and (n>4);
end;

//заполнение массива с 1 условием
procedure input(var a:matrix; var n:byte);
var
i,j:byte;
begin
  for i:=1 to n do begin
    for j:=1 to n do begin
      a[i,j]:=0;
      if i=j then a[i,j]:=1;
    end;
  end;
end;

//вывод массива
procedure output(var a:matrix; var n:byte);
var 
i,j:byte;
begin
  writeln('Полученная матрица: ');
  for i:=1 to n do begin
    for j:=1 to n do write (a[i,j],' ');
    writeln;
  end;
end;
  
begin
  limit(n);
  input(a,n);
  output(a,n);
end.