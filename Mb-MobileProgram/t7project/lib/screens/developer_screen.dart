import 'package:flutter/material.dart';

class DeveloperScreen extends StatelessWidget {
  const DeveloperScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Информация о разработчике')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text('ФИО: Стич Назар Иванович'),
            SizedBox(height: 10),
            Text('Группа: ИВТ-22'),
            SizedBox(height: 10)
          ],
        ),
      ),
    );
  }
}