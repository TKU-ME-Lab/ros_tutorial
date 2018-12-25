ROS 基本範例
====================
此章節會說明ROS下,節點(Node)間常用的溝通方式


建立Package
--------------------
ROS Package類似於程式專案,程式檔案及相關設定都會在這底下,例如函式庫相依、函式目錄路徑、編譯設定.

這提供兩種方式建立專案,一是透過ROS的catkin指令,二是透過VSCode的插件

首先透過catkin,必須先建立資料夾::
  
  $ mkdir ~/dev/ros_turtorial_ws/src && cd ~/dev/ros_turtorial_ws/src
  $ catkin_create_pkg demo_topic roscpp std_msgs

.. note::
  上面兩句的意思為首先透過mkdir建立資料夾,再透過cd到這個路徑.
  而建立專案則透過catkin_create_pkg,demo_topic為專案名稱,專案名稱必須為英文,roscpp和std_msgs則是相依函式庫  


.. toctree::
		:maxdepth: 1
		:caption: Example

		topicexample











 
