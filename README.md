In front of you the custom widget ComboBox,
it has wrap the text property. This property
will work even if widget has width constraints.
It is quiet simple, but it works.

Перед Вами представлена попытка сделать виджет QComboBox
с возможностью многострочного представления элементов списка.
В базовом варианте исполнения QComboBox сокращает элементы
выпадающего списка (у QComboBox нет метода wrap text), если
длина текста элементов списка длиннее ширины виджета. Такое
поведение может происходить в случае фиксированной ширины
QComboBox. А иногда хочется, чтобы был виден полностью текст строки!
