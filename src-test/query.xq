declare variable $inputdoc external;

let $fbbean := jn:parse-json($inputdoc)

let $location := if(empty($fbbean("location"))) then null else (
	for $local in $fbbean("location")
		let $city := substring-before($local("name"), ", ")
		let $state := substring-after($local("name"), ", ")
		return {
			"city": $city
			,"state": $state
			,"country": $state
		}
)

return $location