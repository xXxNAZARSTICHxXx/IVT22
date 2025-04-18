import 'package:flutter/material.dart';
import 'db_provider.dart';

class DataListScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Список данных'),
      ),
      body: FutureBuilder<List<Map<String, dynamic>>>(
        future: DBProvider.instance.getAllData(),
        builder: (context, snapshot) {
          if (!snapshot.hasData) {
            return Center(child: CircularProgressIndicator());
          }

          final data = snapshot.data!;
          return ListView.builder(
            itemCount: data.length,
            itemBuilder: (context, index) {
              final item = data[index];
              return ListTile(
                title: Text(item['title']),
                subtitle: Text(item['value']),
              );
            },
          );
        },
      ),
    );
  }
}