program N694k;
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

//заполнение массива с 2 условиями
procedure input(var a:matrix; var n:byte);
var
i,j,x:byte;
begin
  for j:=1 to n do begin
    x:=x+1;
    for i:=1 to n do begin
      if j<i then 
      a[i,j]:=n-i+x
      else a[i,j]:=0;
      if i=j then a[i,j]:=n;
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
