TC Service Area


-- SUMMARY --

	The "TC Search Area" module takes any zip code input by user and checks whether or not it matches stored values in the database.

	The application checks for proper formatting locally and uses the ziptasticapi.com API to determine if such a zip code exists and what area the zip code represents. 

	If the zip code is amongst the values stored in the database, the user is redirected to the "Get A Quote" form page.

	If the zip code is not amongst the values stored in the database, the user is redirected to the "Service Area Request" form page.

	If the zip code is not formatted properly the user is prompted to enter a proper value.

	The contact form on the "Service Area Request" and "Get A Quote" pages are for demonstration purposes only and have no functionality.


-- REQUIREMENTS --

 	*This module assumes that an internet connection is available. It makes a curl request to http://ziptasticapi.com. There is no error handling for the request.


-- USAGE --

	Default zip codes are available.(20011,20036,90210,48915) You may modify them if you like.

	Values are modified bu going to admin/blocks and selecting "configure" for the "TC Service Area Block" block in the disabled section.

	It is not necessary to place the block into a region for the demonstration of this module. It is hardcoded to show up in the proper place with hook_preprocess.
	

-- INSTALLATION --

	1.
	Place the module into the sites/all/modules directory and enable.

	2.
	Navigate to /service-area-search to start.










