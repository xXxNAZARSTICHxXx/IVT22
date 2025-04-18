import 'package:flutter/material.dart';
import '../db_provider.dart';
import 'data_list_screen.dart'; // Импорт второго экрана

class MainScreen extends StatefulWidget {
  const MainScreen({Key? key}) : super(key: key);

  @override
  _MainScreenState createState() => _MainScreenState();
}

class _MainScreenState extends State<MainScreen> {
  final _titleController = TextEditingController();
  final _valueController = TextEditingController();

  Future<void> _saveData() async {
    final title = _titleController.text;
    final value = _valueController.text;

    if (title.isNotEmpty && value.isNotEmpty) {
      final data = {'title': title, 'value': value};
      await DBProvider.instance.insert(data);

      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Данные сохранены')),
        );
      }

      _titleController.clear();
      _valueController.clear();
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Ввод данных'),
        leading: IconButton(
          icon: Icon(Icons.list),
          onPressed: () {
            Navigator.push(
              context,
              MaterialPageRoute(builder: (_) => DataListScreen()), // Переход на второй экран
            );
          },
        ),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            TextField(
              controller: _titleController,
              decoration: InputDecoration(labelText: 'Название'),
            ),
            TextField(
              controller: _valueController,
              decoration: InputDecoration(labelText: 'Значение'),
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _saveData,
              child: Text('Сохранить'),
            ),
          ],
        ),
      ),
    );
  }
}