.. _class_Topic:
	
Topic
--------------------
Topic為在ROS裡Node之間溝通最基礎的功能,而要構成透過Topic溝通的元素分成Publisher(發佈者), Subsriber(聆聽者),以及Topic的定義,定義包含訊息的型態和地址。


而這個範例將舉例一個Publisher,一個subscriber透過一個topic溝通

假設已經透過 :ref:`Create package <create_package>` 建立好Package後，
