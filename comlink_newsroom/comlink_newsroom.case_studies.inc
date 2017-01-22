<?php


function recent_case_studies() {
    global $base_url;
    $page = '';
    $published = get_recent_posts(array('case_study'));
    $i = 1;
    if (is_array($published)) {
        foreach ($published as $item) {
            // Get images for each node
            $fid = $item->field_media['und'][0]['fid'];
            $image = file_load($fid);
            // Get taxonomy terms for each node
            $tag_ids = $item->field_tags['und'];
            $page .= '
                <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
                    <div class="newsroom-item">
                        <div class="item-left">
                            <div class="item-date">
                                <div class="day">'.date("j", $item->created).'</div>
                                <div class="month">'.date("F", $item->created).'</div>
                            </div>
                            <div class="item-media" style="background-image: url('.$base_url.'/sites/default/files/'.$image->filename.');"></div><!--/ Item media -->
                        </div>
                        <div class="item-content">
                            <h3><a href="'.$base_url.'/node/'.$item->nid.'" title="'.$item->title.'">'.$item->title.'</a></h3>
                            <div class="item-meta">
                                <span class="item-author"><i class="fa fa-user"></i> '.$item->name.'</span>
                                <span class="meta-seperator">|</span>
                                '.print_tags($tag_ids).'
                                <span class="item-comments"><i class="fa fa-comment"></i>'.$item->comment_count['und'][0]['value'].' Comments</span>
                            </div>
                            <div class="item-teaser">
                                <p>'.truncate_utf8(drupal_html_to_text($item->body['und'][0]['value']), 260, TRUE, TRUE, 500).'</p>
                            </div>
                            <div class="item-controls">
                                <a class="btn btn-primary" href="'.$base_url.'/node/'.$item->nid.'" title="'.$item->title.'">Read More</a>
                            </div>
                        </div><!--/ Item Content -->
                    </div>
                </div>
            ';
        }
    } else {
        $page .= $published;
    }
    return $page.'<br><br>';
}