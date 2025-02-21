program N378b;
const k=8; //обозначение константы
type //создание собственной переменной массива
massive=array[1..k] of real;
var
   x:massive;//введение массива
   i,j:integer;//i,j-параметры для работы циклов;
begin
   writeln('Заполните строчку массива восьмью числами: ');
   for i:=1 to k do //входные данные
     readln(x[i]);
   writeln('Ваш сформированный массив по условию задачи: ');
   for j:=0 to k do begin //возведение в степень + вывод массива
    writeln;
    for i:=1 to 8 do
      write(x[i]**j,' ');
      end;
end.