**************************
ROS 基本範例
**************************
此章節會說明ROS下,節點(Node)間常用的溝通方式,包含

.. _create_package:

Create Package
=====================

ROS Package類似於程式專案,程式檔案及相關設定都會在這底下,例如函式庫相依、函式目錄路徑、編譯設定.

這提供兩種方式建立專案,一是透過ROS的catkin_create_pkg指令,二是透過VSCode的插件

catkin_create_pkg
---------------------------
常用方式如下::
  
  $ catkin_create_pkg Package名稱 依賴專案1 依賴專案2

那假設想建立一個Package名為demo_topic,並依賴roscpp和std_msgs,指令如下::

  $ catkin_create_pkg demo_topic roscpp std_msgs

.. note::
  所以依照上面的例子的話,demo_topic為Package名稱,roscpp和std_msgs則是相依函式庫,另外注意Package必須為英文

VSCode-ROS
---------------------
第一次使用VSCode開啟workspace的資料夾時,ROS插件會詢問是否設定ROS的distro,如果已安裝好kinetic版本,在選項裡就kinetic可以選擇.

選擇好後

.. toctree::
		:maxdepth: 1
		:caption: Example

		topicexample











 
