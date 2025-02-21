program N119e; //начало программы
var i,x,e,sum,m,c,d,s1:real;  //декларативная часть
 Logic: boolean;  //декларативная часть
  Question: Char;  //декларативная часть
  Way: string;  //декларативная часть
  YourFile: text;  //декларативная часть
begin //начало исполнительной части
  Logic:=false;
  writeln('Напиши адрес для создания отчета:');
  Readln(way);
  Assign(YourFile, Way);
  if FileExists(Way)= False then Rewrite(YourFile) else Append(YourFile);
  while logic = false do begin

    sum:=0; //обнуляем сумматор
    e:=2; //для повторений мы делаем точность вне цикла
    s1:=1; //промежуточный ответ - присваиваем еденицу для упрощения программ
    c:=1;
    d:=25;
    repeat //цикл - защита от ДУРАКА
    write('Введите точность e (желательно мелкое - 0.001, главное, чтобы оно было >0 или <1): '); //*дружественный интерфейс*
    readln(e); //ввод e
    until(e>0)and(e<1); //цикл - защита от ДУРАКА
    while x>e do begin // цикл while
     s1:=1/(c+d); // выполняем пример по условию,записывая его в x
     c:=c*4;
     d:=d*5;
     sum:=sum+s1; // добавляем ответ к сумматору
    end; // конец исполнительной части цикла

writeln(Yourfile, 'Результатом этого выражения является = ',sum:0:6); // *дружественный интерфейс*
Writeln('Хотите использовать программу еще раз? Y\N');
    Read(Question);
    If question = 'N' then Logic:= True;
  end;
  closefile(YourFile);
end. // конец программы