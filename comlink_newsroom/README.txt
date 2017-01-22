Comlink Newsroom Module


-- SUMMARY --

	This module is a custom solution for our team to easily create and modify the html markup for the display of custom content types without using the views module.

	This custom module creates and displays 4 different custom content types that represent press releases, case studies, newsletters, and ebooks. The content types are included in the modules directory and are available by activating the module which is dependent on the features module.

	When the user adds press releases, case studies, newsletters, or ebooks, the user will be able to navigate to the appropriate page listing and see a list of teasers for that content type.

	A right navigation menu exists consisting of links to the different custom content page listings.



-- REQUIREMENTS --

	* Features Module - https://www.drupal.org/project/features

	* This module was used with a custom theme that has custom fields, namely field_media that holds images and other media files.

	* Twitter bootstrap



-- USAGE --

	Each page displays a list of teasers that corresponds to one of the 4 content types in a block named 'comlink_newsroom_content_block' on the left side. A navigation menu is displayed in the block named 'comlink_newsroom_nav_block' on the right side which shows buttons that link to the display list of each content type.

	This custom module creates 5 pages using hook_theme and hook_menu:
	newsroom (displays all of 4 content type records in order by date)
	newsroom/press_releases
	newsroom/newsletter
	newsroom/case_studies
	newsroom/ebooks

	Designers can directly manipulate all of the html output in this module in the following files;
	 
	 - comlink_newsroom.module (navigation menu)

	 - comlink_newsroom.homepage.inc (teaser list)
	 - comlink_newsroom.case_studies.inc (teaser list)
	 - comlink_newsroom.press_releases.inc (teaser list)
	 - comlink_newsroom.newsletters.inc (teaser list)
	 - comlink_newsroom.ebooks.inc (teaser list)
	 - comlink_newsroom.ebooks.inc (teaser list) 

	 /templates
	 - node--press_releases.tpl.php (single record page) 
	 - node--newsletter.tpl.php (single record page) 
	 - node--ebooks.tpl.php (single record page) 
	 - node--case_study.tpl.php (single record page) 
	 
	Each file contains a function that returns the corresponding html markup as a result of the get_recent_posts() function that does an entity field query for the specified content type. The designers can use the return values to have greater control over the manipulation of the data to make a clean and engaging list of records without using the views module. 

	The templates folder contains the node.tpl.php files for each content type so that the designer can control the display of each individual record.

	Each block is programmed to exist in the regions 'newsroom_right_nav' and 'newsroom_left_content' defined in the theme .info file and should show up on the following pages;
	  - newsroom
	  - newsroom/press_releases
	  - newsroom/newsletter
	  - newsroom/case_studies
	  - newsroom/ebooks

	The $block['content'] in the hook_block_view() function is populated by custom functions to dynamically produce the correct data using the 'current_content()' function. This function has a switch statemnent that dynamically calls the appropriate content function. 

	These content functions return html markup where the variables are pulled from a call to get_recent_posts(). This function does an entity field query to get the appropriate content type. Three parameters can be passed; 
	  - array $types - An array of content type machine names.
	  - string $orderby - that can take either ASC for ascending order or DESC for descending order
	  - int $pager an integer setting the value for the number of requested records.

	The navigation block is populated by a function titled 'comlink_newsroom_nav_block_content()'. This function returns a block of static html code creating 5 stacked pill buttons where the active/inactive css bootstrap class is changed dynamically based on the current url. 





-- INSTALLATION --

	1.
	Add the following regions in the theme .info file:
	regions[newsroom_right_nav] = Newsroom - Right Nav
	regions[newsroom_left_content] = Newsroom - Content Left

	2.
	Enable ‘Comlink Newsroom Content Types’ module
	Content types that will be available
	'press_release', 'case_study’,’newsletter’, ‘ebook’

	3.
	Enable ‘Comlink Newsroom’ module

	4.
	Blocks(created in module):
	'comlink_newsroom_nav_block' and 'comlink_newsroom_content_block' (should auto populate -- ignore drush warning -- check blocks page)

	Blocks should show up only on —
	newsroom
	newsroom/press_releases
	newsroom/newsletter
	newsroom/case_studies
	newsroom/ebooks
	—

	5. (only for use with themes that use drupal exp theme module)
	Appearance page:
	create ‘Newsroom Section’
	add nav and content regions to ‘Newsroom Section’

	Should show up only on —
	newsroom
	newsroom/press_releases
	newsroom/newsletter
	newsroom/case_studies
	newsroom/ebooks
	—







